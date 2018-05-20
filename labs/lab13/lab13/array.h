#include <stdlib.h>
#define ROWS 200
#define COLS 100
#define foreachrow(VAR) for(VAR=0; VAR<ROWS; VAR++)
#define foreachcol(VAR) for(VAR=0; VAR<COLS; VAR++)

int ** allocateArray();
void freeArray(int **array);