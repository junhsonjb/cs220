#ifndef LINES_H
#define LINES_H
#include <stdbool.h>

typedef struct lines_data *linesptr;

linesptr lines_create(int n);
void line_setValid(linesptr lines,int line);
bool line_isValid(linesptr lines,int line);
void line_setUsed(linesptr lines,int line);
int line_firstUsed(linesptr lines,int start, int end);
void line_setDirty(linesptr lines,int line);
bool line_isDirty(linesptr lines,int line);
void report_lineStats(linesptr lines);
void lines_free(linesptr lines);
#endif
