#include <stdio.h>
#include <string.h>

enum lineTypes { string, hex, address, comment, eof, error };
enum lineTypes nextLine(char **valPtr);

int main() {
	// Reads stdin and writes to stdout
	// Each line in stdin must be preceded by a prefix character:
	//    'S' - Read this line as an ASCII string (up to the newline character)
	//    'X' - Read this line as a list of hexadecimal bytes (two hex chars per byte)
	//    'A' - Read this line as a hexadecimal 64 bit address
	//    '#' - Read this line as a comment (ignore the remainder of this line

	enum lineTypes lt;
	char *dstring;
	char hexVal;
	union addrChar {
		void * addr;
		char bytes[8];
	} ach;
	while(eof != (lt = nextLine(&dstring))) {
		switch(lt) {
			case comment: continue;
			case string: printf("%s",dstring); break;
			case hex:
				while((*dstring) != 0x00) { // Read until we get to the end of the line
					if ((*dstring)==' ') { dstring++; continue; } // Skip blank spaces
					if (1 != sscanf(dstring,"%2hhx",&hexVal)) {
						fprintf(stderr,"Please use only hexadecimal characters on hex lines... got %s (that starts with %2hhx)\n",dstring,dstring[0]);
						return 1; // quit with error
					}
					putchar(hexVal);
					dstring+=2;
				}
				break;
			case address :
				if (1!=sscanf(dstring,"%p",&ach.addr)) {
					fprintf(stderr,"Please use only hexadecimal values on address lines... got %s\n",dstring);
					return 2; // quit with error
				}
				int i;
				for(i=0;i<8;i++) {
					putchar(ach.bytes[i]);
				}
				break;
			default:
				fprintf(stderr,"Invalid input line: %s\n",dstring);
				return 3;
		}
	}
	return 0;
}

	enum lineTypes nextLine(char **valPtr) {
		static char buffer[256];
		(*valPtr)=NULL;
		if (feof(stdin)) return eof;
		if (NULL==fgets(buffer,sizeof(buffer),stdin)) return eof;
		(*valPtr)=buffer+2;
		buffer[strlen(buffer)-1]=0x00; // Remove \n from buffer
		switch(buffer[0]) {
			case 'S' : return string;
			case 'X' : return hex;
			case 'A' : return address;
			case '#' : return comment;
			default: return error;
		}
		return error;
	}


