#include<stdio.h>
#include<stdlib.h>

int main(void) {
  char input[1000][10];
  int inputCount = 0;
  char direction[1000];
  int value[1000];
  int x = 0;
  int y = 0;
  int shipAngle = 0;
  int wx = 10;
  int wy = 1;
  int temp = 0;
  while(scanf("%s", input[inputCount++]) == 1);

  for(int i = 0; i < inputCount - 1; i++) {
    direction[i] = input[i][0];
    value[i] = atoi(input[i] + 1);

    printf("x: %d, y: %d, wx: %d, wy:%d, shipAngle: %d\n", x, y, wx, wy, shipAngle);
    printf("direction: %c, value: %d\n", direction[i], value[i]);
    switch(direction[i]) {
    case 'N':
      wy += value[i];
      break;
    case 'S':
      wy -= value[i];
      break;
    case 'E':
      wx += value[i];
      break;
    case 'W':
      wx -= value[i];
      break;
    case 'L':
      switch(value[i]) {
      case 0:
	break;
      case 90:
	temp = wx;
	wx = wy;
	wy = temp;
	wx *= -1;
	break;
      case 180:
	wx *= -1;
	wy *= -1;
	break;
      case 270:
	temp = wx;
	wx = wy;
	wy = temp;
	wy *= -1;
	break;
      default:
	printf("should not reach here.\n");
	break;
      }
      break;
    case 'R':
      if(shipAngle < 0) shipAngle += 360;
      if(shipAngle >= 360) shipAngle -= 360;
      switch(value[i]) {
      case 0:
	break;
      case 90:
	temp = wx;
	wx = wy;
	wy = temp;
	wy *= -1;
	break;
      case 180:
	wx *= -1;
	wy *= -1;
	break;
      case 270:
	temp = wx;
	wx = wy;
	wy = temp;
	wx *= -1;
	break;
      default:
	printf("should not reach here.\n");
	break;
      }
      shipAngle = 0;
      break;
    case 'F':
      x += (wx * value[i]);
      y += (wy * value[i]);
      break;
    }
  }
  printf("x: %d, y: %d\n", x, y);
  if(x < 0) x *= -1;
  if(y < 0) y *= -1;
  printf("ans: %d\n", x + y);
  return 0;
}
