#include<stdio.h>
#include<stdlib.h>

int main(void) {
  long int input[1000];
  int inputCount = 0;
  int preamble = 25;
  int ansIndex = 0;
  while(scanf("%ld", &input[inputCount++]) == 1);
  
  for(int i = preamble; i<inputCount-1; i++) {
    int found = 0;
    for(int j = i - preamble; j<i-1; j++) {
      for(int k = j + 1; k < i; k++) {
	if(input[k] + input[j] == input[i]) {
	  found = 1;
	}
      }
    }
    if(found == 0) {
      ansIndex = i;
      break;
    }
    //printf("%ld\n", input[i]);
  }
  printf("ans: %ld\n", input[ansIndex]);
  
  int firstIndex = 0;
  int lastIndex = 0;
  long contiguousSum = 0;

  while(lastIndex < inputCount - 1) {
    if(contiguousSum == input[ansIndex]) {
      break;
    }
    
    //printf("con: %ld\n", contiguousSum);
    
    if(contiguousSum > input[ansIndex]) {
      contiguousSum -= input[firstIndex++];
      //printf("minus %ld\n", contiguousSum);
    }
    else {
      contiguousSum += input[lastIndex++];
    }
    
  }
  
  printf("%d\n", inputCount);
  printf("firstIndex: %d, %ld\n", firstIndex, input[firstIndex]);
  printf("lastIndex: %d, %ld\n", lastIndex - 1, input[lastIndex - 1]);

  long max = 0;
  long min = 999999999999999;

  for(int i = firstIndex; i < lastIndex; i++) {
    if(input[i] > max) max = input[i];
    if(input[i] < min) min = input[i];
  }

  printf("max %ld, min %ld, add: %ld", max, min, max+min);
 
  return 0;
}


