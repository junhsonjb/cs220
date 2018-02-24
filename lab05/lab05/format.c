#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "format.h"

const char nullLine[1]={0x00};
char ** pointsTo(void *ptr, char **lines);

char **formatPointer(void *data) {
	// Assumes pointers are 8 bytes!
	char * line1=(char *)malloc(PTRSIZE+3);
	line1[0]='+';
	int i;
	for(i=1;i<=PTRSIZE;i++) line1[i]='-';
	line1[PTRSIZE+1]='+';
	line1[PTRSIZE+2]=0x00;
	char * line2=(char *)malloc(PTRSIZE+4);
	sprintf(line2,"|%8lx|",(unsigned long)data);
	char **ret=(char **)malloc(4*PTRSIZE);
	ret[0]=line1;
	ret[1]=line2;
	ret[2]=strdup(line1);
	ret[3]=(char *)nullLine;
	return ret;
}

char ** formatScalar(float *data) {
	char **lines=malloc(2*PTRSIZE);
	char * value=(char *)malloc(16);
	sprintf(value,"%f",(*data));
	lines[0]=value;
	lines[1]=(char *)nullLine;
	return pointsTo((void *)data,lines);
}

char **formatVector(float * data,int len) {
	char **lines=malloc(2*PTRSIZE);
	char * value=(char *)malloc(16*len);
	sprintf(value,"%f",data[0]);
	int i;
	for(i=1;i<len;i++) {
			sprintf(value,"%s, %f",value,data[i]);
	}
	lines[0]=value;
	lines[1]=(char *)nullLine;
	return pointsTo(data,lines);
}

char ** formatMatrix(float * data,int rows,int cols) {
	char **lines=malloc((rows+1)*PTRSIZE);
	int r;
	for(r=0;r<rows;r++) {
		char * values=malloc(16*cols);
		sprintf(values,"%f",*(data+r*cols));
		int c;
		for(c=1;c<cols;c++) {
			sprintf(values,"%s,%f",values,*(data+r*cols+c));
		}
		lines[r]=values;
	}
	lines[rows]=(char *)nullLine;
	return pointsTo(data,lines);
}

char ** formatPointerList(float **data,int nptrs) {
	// data points to a list of pointers to floats
	char **lines=(char **)malloc((3*nptrs+1)*PTRSIZE);
	int i;
	for(i=0;i<nptrs;i++) {
		char **slines=formatScalar(*(data+i));
		lines[i*3]=slines[0];
		lines[i*3+1]=slines[1];
		lines[i*3+2]=slines[2];
		free(slines);
	}
	lines[3*nptrs]=(char *)nullLine;
	return pointsTo(data,lines);
}

char ** formatPointerVectorList(float **data, int nptrs, int len) {
	// data points to a list of pointers to vectors of floats
	char **lines=(char **)malloc((3*nptrs+1)*PTRSIZE);
	int i;
	for(i=0;i<nptrs;i++) {
		char **slines=formatVector(*(data+i),len);
		lines[i*3]=slines[0];
		lines[i*3+1]=slines[1];
		lines[i*3+2]=slines[2];
		free(slines);
	}
	lines[3*nptrs]=(char *)nullLine;
	return pointsTo(data,lines);
}

char ** formatPointerPointerList(float ***data,int nptr1,int nptr2) {
	// data points to a list of pointers to pointers to floats
	char **lines=(char **)malloc((3*nptr1*nptr2+4)*PTRSIZE);
	int i;
	for(i=0;i<nptr1;i++) {
		char **slines=formatPointerList(*(data+i),nptr2);
		int j;
		int start=i*(nptr2*3+1);
		for(j=0;slines[j][0]!=0x00;j++) {
			lines[start+j]=slines[j];
		}
		free(slines);
	}
	lines[nptr1*3*nptr2+3]=(char *)nullLine;
	return pointsTo(data,lines);
}

char ** pointsTo(void *ptr, char **lines) {
	int nl=0;
	for(nl=0;lines[nl][0]!=0x00;nl++) {}
	char **plines=formatPointer(ptr);
	char **nlines=malloc(((nl>2) ? (nl+2) : 4) * PTRSIZE);
	nlines[0]=plines[0];
	char * newLine1=(char *)malloc(strlen(plines[1])+5+strlen(lines[0]));
	sprintf(newLine1,"%s -> ",plines[1]);
	free(plines[1]);
	int offset=strlen(newLine1);
	strcat(newLine1,lines[0]);
	free(lines[0]);
	nlines[1]=newLine1;
	if (nl>1) {
		char * newLine2=(char *)malloc(offset+strlen(lines[1])+1);
		sprintf(newLine2,"%-*s%s",offset,plines[2],lines[1]);
		nlines[2]=newLine2;
		free(plines[2]); free(lines[1]);
	} else {
		nlines[2]=plines[2];
	}
	int ln;
	for(ln=2;ln<nl;ln++) {
		char *newLine=(char *)malloc(offset+strlen(lines[ln])+1);
		sprintf(newLine,"%-*s%s",offset," ",lines[ln]);
		nlines[ln+1]=newLine;
		free(lines[ln]);
	}
	if (nl<2) nl=2;
	nlines[nl+1]=(char *)nullLine;
	free(plines);
	free(lines);
	return nlines;
}



void printFormat(char *descr, char **lines) {
	printf("%s\n",descr);
	int i;
	for(i=0; lines[i][0]!=0x00; i++) {
		printf("   %s\n",lines[i]);
		free(lines[i]);
	}
	free(lines);
}