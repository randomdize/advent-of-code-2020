#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
int main(void) {
  int startTime;
  char input[200];
  int bus[50];
  int busCount = 0;
  int offset[50];
  int offsetValue = 0;

  scanf("%d", &startTime);
  scanf("%s", input);

  printf("%d, %s\n", startTime, input);

  char* pch;
  pch = strtok(input, ",");
  while(pch != NULL) {
    printf("%s\n", pch);
    if(strcmp(pch, "x") != 0) {
      offset[busCount] = offsetValue;
      bus[busCount++] = atoi(pch);
    }
    offsetValue++;
    pch = strtok(NULL, ",");
  }/*
  printf("\n");
  int min = 9999999;
  int busId = 0;
  for(int i = 0; i < busCount; i++) {
    if(startTime % bus[i] == 0) {
      min = 0;
      busId = bus[i];
      break;
    }
    int a = bus[i] * ((startTime / bus[i]) + 1) - startTime;
    if(a < min) {
      min = a;
      busId = bus[i];
    }
  }

  printf("ans: %d id: %d ans: %d \n", min, busId, min * busId);
   */
  for(int i = 0; i < busCount; i++) {
    printf("busid: %d, offset: %d\n", bus[i], offset[i]);
  }
  
  /*
  long counter = (long)bus[0];
  int found = 0;
  while(found == 0) {
    //printf("f %ld\n", counter);
    for(int i = 1; i <= busCount; i++) {
      if(i == busCount) {
	found = 1;
	break;
      }
      if((counter + offset[i]) % bus[i] != 0) {
	break;
      }
    }
    counter += bus[0];
  }

  printf("%ld", counter - (long)bus[0]);
  */

  long n = 0;
  long cc = 1;
  long t = 1;
  for(int i = 0; i < busCount;i++) {
    cc = 1;
    for(int j = 0; j < busCount; j++) {
      if(j == i) continue;
      cc = cc * bus[j];
      //printf("cc %d\n", cc);
    }
    //printf("co: %ld\n", cc);
    long co = cc;
    while((cc+offset[i])%bus[i] != 0) {
      //printf("c2 %ld\n", cc);
      cc = cc + co;
    }
    printf("%ld + %d , %d\n", cc, offset[i], bus[i]);
    n += cc;
    t *= bus[i];
    printf("\n");
  }
  while(1) {
    if(n - t < 0) {
      break;
    }
    n = n - t;
  }
  printf("ans: %ld\n", n);
  //printf("%d + %ldt, %ld\n", n, t, n - t);
  
  return 0;
}
