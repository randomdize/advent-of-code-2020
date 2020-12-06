#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int checktree(int, int, char[400][32], int);

int main(void) {
  char map[400][32];
  int count = 0;
  while(scanf("%s", map[count++]) == 1);
  printf("1-1: %d\n", checktree(1, 1, map, count));
  printf("3-1: %d\n", checktree(3, 1, map, count));
  printf("5-1: %d\n", checktree(5, 1, map, count));
  printf("7-1: %d\n", checktree(7, 1, map, count));
  printf("1-2: %d\n", checktree(1, 2, map, count));
  long ans = (long)checktree(1, 1, map, count)
    * (long)checktree(3, 1, map, count)
    * (long)checktree(5, 1, map, count)
    * (long)checktree(7, 1, map, count)
    * (long)checktree(1, 2, map, count);
  printf("%lu", ans);
  return 0;
}

int checktree(int right, int down, char map[400][32], int count) {
  int x = 0;
  int tree = 0;
  int mapLength = strlen(map[0]);
  //printf("mapLength = %d\n", mapLength);
  for(int y = 0; y < count - 1; y += down) {
    //printf("x = %d, y = %d\n", x, y);
    if(map[y][x] == '#') {
      tree += 1;
    }
    x = x + right;
    if(x > mapLength - 1) {
      x = x - mapLength;
    }
  }
  return tree;
}
