#ifndef CAM_H
#define CAM_H

typedef struct cam_data *camptr;

camptr cam_create(int rows,long initval);
void cam_write(camptr cam,int address,unsigned long value);
int cam_read(camptr cam,unsigned long value);
unsigned long cam_value(camptr cam,int address);
void cam_free(camptr cam);

#endif
