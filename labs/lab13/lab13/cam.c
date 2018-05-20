#include "cam.h"
#include <stdlib.h>
#include <assert.h>

struct cam_data {
	int rows;
	unsigned long *data;
};

camptr cam_create(int rows,long initval) {
	camptr cam = (camptr)malloc(sizeof(struct cam_data));
	assert(cam);
	cam->rows=rows;
	cam->data=(unsigned long *)malloc(rows*sizeof(unsigned long));
	assert(cam->data);
	int i;
	for(i=0;i<rows;i++) {
		cam->data[i]=initval;
	}
	return cam;
}

void cam_write(camptr cam,int address, unsigned long value) {
	assert(cam);
	assert(address<cam->rows);
	cam->data[address]=value;
}

int cam_read(camptr cam,unsigned long value) {
	assert(cam);
	int i;
	for(i=0;i<cam->rows;i++) {
		if (cam->data[i]==value) return i;
	}
	return -1;
}

unsigned long cam_value(camptr cam,int address) {
	assert(cam);
	assert(address<cam->rows);
	return cam->data[address];
}

void cam_free(camptr cam) {
	assert(cam);
	free(cam->data);
	cam->data=NULL;
	free(cam);
}

