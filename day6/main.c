#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
  char input[3000][200];
  int count = 0;
  char question[3000][200];
  int questcount = 0;
  int ans = 0;
  int person[3000];
  int allans = 0;

  for(int i = 0; i < 3000; i++) person[i] = 0;
  
  while(fgets(input[count++], 200, stdin) != NULL);
  for(int i = 0; i < count-1; i++) {
    //printf("%s", input[i]);
    if(strcmp(input[i], "\n") == 0) {
      questcount++;
    }
    else {
      if(input[i][strlen(input[i])-1]=='\n') {
	input[i][strlen(input[i])-1] = '\0';
      }
      strcat(question[questcount], input[i]);
      person[questcount] += 1;
    }
  }
  for(int i = 0; i < questcount+1; i++) {
    char buff[100];
    int buffcount = 0;
    for(int j = 0; j < strlen(question[i]); j++) {
      int isAlreadyExist = 0;
      for(int k = 0; k < buffcount; k++) {
	if(question[i][j] == buff[k]) {
	  isAlreadyExist = 1;
	  break;
	}
      }
      if(isAlreadyExist == 0) {
	buff[buffcount] = question[i][j];
	buffcount = buffcount + 1;
      }
    }
    printf("bufcount %d person %d\n", buffcount, person[i]);
    printf("question %s\n", question[i]);
    ans = ans + buffcount;
    for(int j = 0; j < buffcount; j++) {
      int occur = 0;
      for(int k = 0; k < strlen(question[i]); k++) {
	if(buff[j] == question[i][k]) occur++;
      }
      if(occur == person[i]) allans++;
    }
  }
  printf("ans %d\n", ans);
  printf("allans %d\n", allans);
  return 0;
}
