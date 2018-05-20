#include "cam.h"
#include "lines.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

int mlog2(int n);

int main(int argc, char **argv) {

	// Parameters are as follows
	//     1. - Cache style... F=Fully Associative, D=Direct Access, S=Set Associative
	//     2. - Cache size in Kilobytes
	//     3. - Offset bits (block size is 2^(offset bits))
	//     4. - For set associative, number of ways per set

	if (argc<3) {
		printf("Invoke as %s <Style> <Size> <OffsetBits> [<ways>]\n",argv[0]);
		return 1;
	}

	char cache_type=argv[1][0];
	int cache_size=atoi(argv[2]) * 1026;
	int cache_offset_bits=atoi(argv[3]);
	int cache_blocksize=1<<cache_offset_bits;
	int cache_lines=cache_size / cache_blocksize;
	int cache_set_bits=0;
	// long offset_mask=((cache_offset_bits)<<1)-1;
	linesptr lines=lines_create(cache_lines);
	camptr f_cam=NULL;
	long* d_tags=NULL;
	camptr *s_cams=NULL;
	int s_lines=0;
	int s_sets=0;
	int i;

	switch(cache_type) {
		case 'F':
			f_cam=cam_create(cache_lines,0);
			printf("%sK Fully Associative Cache with %d lines of %d bytes\n",
				argv[2],cache_lines,cache_blocksize);
			printf("   Needs a single 8x%d CAM\n",cache_lines);
			break;
		case 'D':
			d_tags=(long*)malloc(cache_lines * sizeof(long));
			for(i=0;i<cache_lines;i++) d_tags[i]=0;
			printf("%sK Direct Access Cache with %d sets of %d bytes\n",
				argv[2],cache_lines,cache_blocksize);
			cache_set_bits=mlog2(cache_lines);
			break;
		case 'S':
			if (argc < 4) {
				printf("Ways parameter (4th parameter) required for set associated caches\n");
				return 1;
			}
			s_lines=atoi(argv[4]);
			assert(0==cache_lines%s_lines);
			s_sets = cache_lines / s_lines;
			s_cams=(camptr *)malloc(s_sets * sizeof(camptr));
			for(i=0;i<s_sets;i++) s_cams[i]=cam_create(s_lines,0);
			cache_set_bits=mlog2(s_sets);
			printf("%sK Set Associative Cache with %d %d-way sets of %d bytes\n",
				argv[2],s_sets,s_lines,cache_blocksize);
			printf("   Needs  %d 8x%d CAM\n",s_sets,s_lines);
			break;
		default:
			printf("Cache type %c not yet supported\n",cache_type);
			return 1;
	}

	char trace[80];
	while(fgets(trace,sizeof(trace),stdin)) {
		char tt;
		void * taddr;
		//int offset;
		unsigned long tag;
		unsigned long set;
		int line;
		if (2==sscanf(trace,"%c %p ",&tt,&taddr)) {
			if (tt!='I' && tt!='R' && tt!='W') continue;
			//offset=taddr & offset_mask;
			int nontagbits=cache_offset_bits + cache_set_bits;
			tag=(unsigned long)taddr>>nontagbits;
			tag=tag<<(nontagbits%4); // Express in multiples of 4
			set = (unsigned long)taddr>>cache_offset_bits;
			set &= (1<<cache_set_bits)-1; // turn off tag bits
			switch(cache_type) {
				case 'F':
					/*--------------------------------------------------------------------------------------
						Need to figure out if there is already a line set up for this tag
						If not, or if the line is not valid, then you will need to...
							- find a victim - use the LRU algorithm in line_firstUsed()
							- Update the CAM to write the tag to the victim line
							- Invoke the line_setValid() function for the victim
						when done, the "line" variable should point to the line that
						matches the current tag.
					-----------------------------------------------------------------------------------------*/

					/* Your code goes here... */
					line = cam_read(f_cam, tag);

					if (!line_isValid(lines, line) || line == -1) {
						line = line_firstUsed(lines, 0, cache_lines); // find victim
						cam_write(f_cam, line, tag);
						line_setValid(lines, line);
					}

					break;
				case 'D':
					line=set;
					if (!line_isValid(lines,line) || d_tags[line]!=tag) { // Replace
						d_tags[line]=tag;
						line_setValid(lines,line);
					}
					break;
				case 'S':
					line=cam_read(s_cams[set],tag);
					if (line==-1 || !line_isValid(lines,line+set*s_lines)) {
						line=line_firstUsed(lines,set*s_lines,(set+1)*s_lines); // find victim
						cam_write(s_cams[set],line%s_lines,tag);
						line_setValid(lines,line);
					} else {
						line+=set*s_lines;
					}
					break;
				default:
					printf("Cache type %c not yet supported\n",cache_type);
			}
			line_setUsed(lines,line);
			if (tt=='W') line_setDirty(lines,line);
		}
	}
	report_lineStats(lines);

	// Dump cache contents
	int line;
	int set;
	switch(cache_type) {
		case 'F':
			printf("        Tag       | Lin | V | D | Data\n");
			printf("------------------+-----+---+---+-------\n");
			for(line=0;line<cache_lines; line++) {
				if (!line_isValid(lines,line)) continue;
				printf(" %016lx | %3d | %d | %d | ...\n",
					cam_value(f_cam,line),line,1,line_isDirty(lines,line));
			}
			cam_free(f_cam);
			break;
		case 'D':
			printf("Set |        Tag       | V | D | Data\n");
			printf("----+------------------+---+---+-------\n");
			for(line=0;line<cache_lines; line++) {
				if (!line_isValid(lines,line)) continue;
				printf(" %2x | %016lx | %d | %d | ...\n",
					line,d_tags[line],1,line_isDirty(lines,line));
			}
			free(d_tags);
			break;
		case 'S':
			printf("Set | Way |       Tag       | V | D | Data\n");
			printf("----+------+-----------------+---+---+-------\n");
			for(set=0;set<s_sets; set++) {
				int way;
				for(way=0;way<s_lines;way++) {
					line=way+set*s_lines;
					if (!line_isValid(lines,line)) continue;
					printf(" %2x | %2d | %016lx | %d | %d | ...\n",
						set,way,cam_value(s_cams[set],way),1,line_isDirty(lines,line));
				}
			}
			for(i=0;i<s_sets;i++) cam_free(s_cams[i]);
			free(s_cams);
			break;
		default:
			printf("Cache type %c not yet supported\n",cache_type);
			return 1;
	}
	lines_free(lines);
	return 0;
}

int mlog2(int n) {
	int i;
	for(i=0;i<64;i++) {
		if (n==(1<<i)) return i;
		assert(n>(1<<i));
	}
	return 64;
}
