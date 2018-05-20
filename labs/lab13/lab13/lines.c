#include "lines.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct line_struct {
		bool valid;
		bool dirty;
		int lastUsed;
};

static int time=1;

struct lines_data {
	int n;
	struct line_struct *lines;
	int misses;
	int hits;
	int writes;
};

linesptr lines_create(int n) {
	linesptr lines=(linesptr) malloc(sizeof(struct lines_data));
	assert(lines);
	lines->n=n;
	lines->lines=(struct line_struct *)malloc(n*sizeof(struct line_struct));
	lines->misses=0;
	lines->hits=0;
	lines->writes=0;
	int i;
	for(i=0;i<n;i++) {
		lines->lines[i].valid=false;
		lines->lines[i].dirty=false;
		lines->lines[i].lastUsed=0;
	}
	return lines;
}

void line_setValid(linesptr lines,int line) {
	assert(lines);
	assert(line<lines->n);
	lines->misses++;
	if (lines->lines[line].valid && lines->lines[line].dirty) lines->writes++;
	lines->lines[line].valid=true;
	lines->lines[line].dirty=false;
}

bool line_isValid(linesptr lines,int line) {
	assert(lines);
	assert(line<lines->n);
	return lines->lines[line].valid;
}

void line_setUsed(linesptr lines,int line) {
	assert(lines);
	assert(line<lines->n);
	assert(lines->lines[line].valid);
	lines->hits++;
	lines->lines[line].lastUsed=time;
	time++;
}

int line_firstUsed(linesptr lines,int start, int end) {
	assert(lines);
	assert(start>=0);
	assert(end>start);
	assert(end<=lines->n);
	int i; int first=start; int oldest;
	oldest=time+1;
	for(i=start;i<end;i++) {
		if (!lines->lines[i].valid) return i;
		if (oldest>lines->lines[i].lastUsed) {
			first=i;
			oldest=lines->lines[i].lastUsed;
		}
	}
	return first;
}

void line_setDirty(linesptr lines,int line) {
	assert(lines);
	assert(line<lines->n);
	lines->lines[line].dirty=true;
}

bool line_isDirty(linesptr lines,int line) {
	assert(lines);
	assert(line<lines->n);
	return lines->lines[line].dirty;
}

void report_lineStats(linesptr lines) {
	assert(lines);
	printf("There were %d cache misses (%d writebacks) and %d hits\n",
		lines->misses,lines->writes,lines->hits);
	printf("For a cache hit rate of %6.2f%%\n",(float)(lines->hits-lines->misses)*100.0 / lines->hits);
}

void lines_free(linesptr lines) {
	assert(lines);
	free(lines->lines);
	free(lines);
}
