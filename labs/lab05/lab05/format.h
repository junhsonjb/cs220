#define PTRSIZE 8 // Assuming 8 byte pointers on this machine

char ** formatPointer(void * data);
char ** formatScalar(float *data);
char ** formatVector(float *data,int len);
char ** formatMatrix(float * data,int rows,int cols);
char ** formatPointerList(float **data,int nptrs);
char ** formatPointerVectorList(float **data, int nptrs, int len);
char ** formatPointerPointerList(float ***data,int nptr1,int nptr2);
void printFormat(char *descr,char **lines);