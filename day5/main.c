#include<stdio.h>
#include<stdlib.h>

int main(void) {
  char input[1000][11];
  int seat[128][8];
  for(int i = 0; i < 128; i++) {
    for(int j = 0; j < 8; j++) {
      seat[i][j] = 0;
    }
  }
  int count = 0;
  int max = 0;
  while(scanf("%s", input[count++]) == 1);
  for(int i = 0; i < count-1; i++) {
    int upper = 127;
    int bottom = 0;
    int xupper = 7;
    int xbottom = 0; 
    for(int j = 0; j < 7; j++) {
      if(input[i][j] == 'F') {
	upper = upper - (((upper - bottom) / 2) + 1);
      }
      else if(input[i][j] == 'B') {
	bottom = bottom + (((upper - bottom) / 2) + 1);
      }
      else {
	printf("FB should not reach here.\n");
      }
    }
    if(upper != bottom) {
      printf("check failed. upper = %d, bottom = %d\n", upper, bottom);
    }
    for(int j = 7; j < 10; j++) {
      if(input[i][j] == 'L') {
	xupper = xupper - (((xupper - xbottom) / 2) + 1);
      }
      else if(input[i][j] == 'R') {
	xbottom = xbottom + (((xupper - xbottom) / 2) + 1);
      }
      else {
	printf("LR should not reach here.\n");
      }
    }
    if(xupper != xbottom) {
      printf("check failed. xupper = %d, xbottom = %d\n", xupper, xbottom);
    }
    /*printf("upper = %d, bottom = %d, xupper = %d, xbottom = %d\n"
	   ,upper
	   ,bottom
	   ,xupper
	   ,xbottom);*/
    int seatid = upper * 8 + xupper;
    printf("%s : row %d, column %d, seatID %d\n", input[i], upper, xupper, seatid);
    seat[upper][xupper] = 1;
    if(seatid > max) max = seatid;
  }
  printf("ans = %d\n", max);
  for(int i = 0; i < 128; i++) {
    for(int j = 0; j < 8; j++) {
      if(seat[i][j] == 0) {
	int seatid = i * 8 + j;
	printf("seat row %d, column %d, seatId %d not taken\n", i, j, seatid);
      }
    }
  }
  return 0;
}
