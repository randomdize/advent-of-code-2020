#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int input[200];
int inputCount = 0;
int combCount = 0;

void tryNext(int currentVolt, int inputIndex) {
  //printf("%d, %d\n", currentVolt, inputIndex);
  if(inputIndex == inputCount - 2) {
    //printf("%d, (%d)\n", currentVolt, currentVolt+3);
    combCount++;
  }
  for(int i = inputIndex + 1; i < inputCount - 1; i++) {
    if(input[i] - currentVolt > 3) {
      return;
    }
    else {
      if(currentVolt == 0) {
	//printf("(0), ");
      }
      else {
	//printf("%d, ", currentVolt);
      }
      tryNext(input[i], i);
    }
  }
}


int main(void) {
  while(scanf("%d", &input[inputCount++]) == 1);

  for(int i = 0; i < inputCount-2;i++) {
    for(int j = i + 1; j < inputCount - 1; j++) {
      if(input[i] > input[j]) {
	int temp = input[i];
	input[i] = input[j];
	input[j] = temp;
      }
    }
  }
  for(int i = 0; i < inputCount-1; i++) {
    printf("%d\n", input[i]);
  }

  int jolt1 = 0;
  int jolt3 = 0;
  int currentjolt = 0;
  
  for(int i = 0; i < inputCount-1;i++) {
    if(input[i] - currentjolt <= 3) {
      if(input[i] -currentjolt == 1) {
	jolt1++;
      }
      if(input[i] - currentjolt == 3) {
	jolt3++;
      }
      currentjolt = input[i];
    }
    else {
      printf("should not reach here.\n");
      break;
    }
  }
  jolt3++;

  printf("jolt1 %d, jolt3 %d, ans %d\n", jolt1, jolt3, jolt1 * jolt3);

  //tryNext(0, -1);

  int currentVolt = 0;
  int lookIndex = 0;
  double pans = 1.0;
  printf("input %d\n", input[inputCount -2]);
  while(currentVolt < input[inputCount - 2]) {
    printf("currentVolt: %d, ", currentVolt);
    int possible = 0;
    int max = 0;
    for(int i = currentVolt + 1; i <= currentVolt + 3; i++) {
      for(int j = lookIndex; j < inputCount - 1; j++) {
	if(input[j] == i) {
	  possible++;
	}
      }
    }
    printf("possible: %d ", possible);
    printf("can skip: %d\n", possible - 1);
    currentVolt = input[lookIndex++];
    //pans *= pow(2, possible - 1);
  }
  printf("ans: %f\n", pans);
  return 0;
}

