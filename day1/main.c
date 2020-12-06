#include<stdio.h>
#include<stdlib.h>

int main(void) {
  long input[300];
  int count = 0;
  while(scanf("%ld", &input[count++]) == 1);
  for(int i = 0; i < count - 3; i++) {
    for(int j = i + 1; j < count - 2; j++) {
      for(int k = j + 1; k < count - 1; k++){
        if(input[i] + input[j] + input[k] == 2020) {
	  printf("%ld", input[i] * input[j] * input[k]);
        }
      }
    }	
  }
  return 0;
}
