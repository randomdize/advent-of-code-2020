#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char input[100][120];
char seat[100][120];
char nextSeat[100][120];
int column = 10;
int row = 10;
int inputCount = 0;

void iter();
char changeStatus(int, int);
int checkAdjacent(int, int);
int checkAdjacent2(int, int);
int checkStop();
void copy();
int countOccupied();
void printSeat();

int main(void) {
  while(scanf("%s", input[inputCount++]) == 1);
  row = inputCount - 1;
  column = strlen(input[0]);
  /*
  for(int y = 0; y < row; y++) {
    for(int x = 0; x < column; x++) {
      printf("%c", input[y][x]);
    }
    printf("\n");
  }
  */
  // first line
  for(int i = 0; i < column + 2; i++) {
    seat[0][i] = '0';
  }

  for(int y = 0; y < row; y++) {
    seat[y + 1][0] = '0';
    for(int x = 0; x < column; x++) {
      seat[y+1][x+1] = input[y][x];
    }
    seat[y + 1][column + 1] = '0';
  }
  // last line
  for(int i = 0; i < column + 2; i++) {
    seat[row+1][i] = '0';
  }

  printf("0\n");
  for(int y = 0; y < row + 2; y++) {
    for(int x = 0; x < column + 2; x++) {
      printf("%c", seat[y][x]);
    }
    printf("\n");
  }
  int iterCount = 0;
  while(1) {
    printf("%d iter\n", iterCount++);
    iter();
    printSeat();
    if(checkStop() == 1) break;
    copy();
  }
  int ans = countOccupied();
  printf("ans: %d", ans);
  return 0;
}

void printSeat() {
  for(int y = 0; y < row + 2; y++) {
    for(int x = 0; x < column + 2; x++) {
      printf("%c", seat[y][x]);
    }
    printf("\n");
  }
}

void iter() {
  for(int y = 0; y < row + 2; y++) {
    for(int x = 0; x < column + 2; x++) {
      nextSeat[y][x] = changeStatus(y, x);
    }
  }
}

int countOccupied() {
  int result = 0;
  for(int y = 0; y < row + 2; y++) {
    for(int x = 0; x < column + 2; x++) {
      if(seat[y][x] == '#') result++;
    }
  }
  return result;
}

void copy() {
  for(int y = 0; y < row + 2; y++) {
    for(int x = 0; x < column + 2; x++) {
      seat[y][x] = nextSeat[y][x];
    }
  }
}

int checkStop() {
  for(int y = 0; y < row + 2; y++) {
    for(int x = 0; x < column + 2; x++) {
      if(seat[y][x] != nextSeat[y][x]) {
	return 0;
      }
    }
  }
  return 1;
}

char changeStatus(int y, int x) {
  if(seat[y][x] == 'L') {
    if(checkAdjacent2(y,x) == 0) {
      return '#';
    }
    else {
      return seat[y][x];
    }
  }
  else if(seat[y][x] == '#') {
    if(checkAdjacent2(y,x) > 4) {
      return 'L';
    }
    else {
      return seat[y][x];
    }
  }
  else if(seat[y][x] == '0') {
    return seat[y][x];
  }
  else if(seat[y][x] == '.') {
    return seat[y][x];
  }
  else {
    printf("should not reach here.\n");
    return 'X';
  }   
}

int checkAdjacent(int y, int x) {
  int count = 0;
  if(seat[y-1][x-1] == '#') count++;
  if(seat[y-1][x] == '#') count++;
  if(seat[y-1][x+1] == '#') count++;
  if(seat[y][x-1] == '#') count++;
  if(seat[y][x+1] == '#') count++;
  if(seat[y+1][x-1] == '#') count++;
  if(seat[y+1][x] == '#') count++;
  if(seat[y+1][x+1] == '#') count++;
  return count;
}

int checkAdjacent2(int y, int x) {
  int count = 0;

  int y2 = y - 1;
  int x2 = x - 1;
  while(seat[y2][x2] != '0') {
    if(seat[y2][x2] == '#') {
      count++;
      break;
    }
    if(seat[y2][x2] == 'L') {
      break;
    }
    y2 -=1;
    x2 -=1;
  }

  y2 = y - 1;
  x2 = x;
  while(seat[y2][x2] != '0') {
    if(seat[y2][x2] == '#') {
      count++;
      break;
    }
    if(seat[y2][x2] == 'L') {
      break;
    }
    y2 -=1;
  }

  y2 = y - 1;
  x2 = x + 1;
  while(seat[y2][x2] != '0') {
    if(seat[y2][x2] == '#') {
      count++;
      break;
    }
    if(seat[y2][x2] == 'L') {
      break;
    }
    y2 -=1;
    x2 +=1;
  }

  y2 = y;
  x2 = x - 1;
  while(seat[y2][x2] != '0') {
    if(seat[y2][x2] == '#') {
      count++;
      break;
    }
    if(seat[y2][x2] == 'L') {
      break;
    }
    x2 -=1;
  }

  y2 = y;
  x2 = x + 1;
  while(seat[y2][x2] != '0') {
    if(seat[y2][x2] == '#') {
      count++;
      break;
    }
    if(seat[y2][x2] == 'L') {
      break;
    }
    x2 +=1;
  }

  y2 = y + 1;
  x2 = x - 1;
  while(seat[y2][x2] != '0') {
    if(seat[y2][x2] == '#') {
      count++;
      break;
    }
    if(seat[y2][x2] == 'L') {
      break;
    }
    y2 +=1;
    x2 -=1;
  }

  y2 = y + 1;
  x2 = x;
  while(seat[y2][x2] != '0') {
    if(seat[y2][x2] == '#') {
      count++;
      break;
    }
    if(seat[y2][x2] == 'L') {
      break;
    }
    y2 +=1;
  }

  y2 = y + 1;
  x2 = x + 1;
  while(seat[y2][x2] != '0') {
    if(seat[y2][x2] == '#') {
      count++;
      break;
    }
    if(seat[y2][x2] == 'L') {
      break;
    }
    y2 +=1;
    x2 +=1;
  }
  return count;
}
