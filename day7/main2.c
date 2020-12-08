#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char input[9000][20];
int inputCount = 0;
int isReadingNumber = 0;
int isReadingBagName = 1;
int isReadingSubBag = 0;
char bagName[600][20];
char subBag[600][600][20];
int subBagCount[600][100];
int subBagTotal[600];
int bagCount = 0;

int doesItHaveShinyGold(int bagIndex) {
  //printf("checking: %s\n", bagName[bagIndex]);
  if(strcmp(bagName[bagIndex], "shiny gold") == 0) return 1;
  for(int i = 0; i < subBagTotal[bagIndex]; i++) {
    for(int j = 0; j < bagCount; j++) {
      if(strcmp(subBag[bagIndex][i], bagName[j]) == 0) {
	if(doesItHaveShinyGold(j) == 1) {
	  return 1;
	}
      }
    }
  }
  return 0;
}

int countBags(int bagIndex) {
  printf("count %s %d\n", bagName[bagIndex], subBagTotal[bagIndex]);
  int ans = 0;
  if(subBagTotal[bagIndex] == 1 && subBagCount[bagIndex][0] == 0) {
    //printf("early exit %s\n", bagName[bagIndex]);
    return 0;
  }
  for(int i = 0; i < subBagTotal[bagIndex]; i++) {
    for(int j = 0; j < bagCount; j++) {
      if(strcmp(subBag[bagIndex][i], bagName[j]) == 0) {
	printf("%s bag has %d %s bag\n", bagName[bagIndex], subBagCount[bagIndex][i], subBag[bagIndex][i]);
	ans = ans + subBagCount[bagIndex][i] +  (subBagCount[bagIndex][i] * countBags(j));
      }
    }
  }
  printf("%s bag has %d bag\n", bagName[bagIndex], ans);
  return ans;
}

int main(void) {
  
  for(int i=0;i<600;i++) subBagTotal[i] = 0;
  
  while(scanf("%s", input[inputCount++]) == 1);
  int iter = 0;
  while(iter < inputCount - 1) {
    if(isReadingBagName == 1) {
      if(strcmp(input[iter + 1], "bags") == 0) {
	strcat(bagName[bagCount], input[iter]);
	isReadingBagName = 0;
	isReadingNumber = 1;
	iter = iter + 2;
      }
      else {
	strcat(bagName[bagCount], input[iter]);
	strcat(bagName[bagCount], " ");
      }
    }
    else if(isReadingNumber == 1) {
      //printf("reading number: %s\n", input[iter]);
      subBagCount[bagCount][subBagTotal[bagCount]] = atoi(input[iter]);
      //printf("sub number: %d\n", subBagCount[bagCount][subBagTotal[bagCount]]);
      isReadingNumber = 0;
      isReadingSubBag = 1;
    }
    else if(isReadingSubBag == 1) {
      //printf("subBag: %s\n", subBag[bagCount][subBagTotal[bagCount]]);
      //printf("reading: %s\n", input[iter]);
      if(input[iter + 1][strlen(input[iter + 1]) - 1] == ',') {
	//printf("reading subBagName end : %s\n", input[iter]);
	strcat(subBag[bagCount][subBagTotal[bagCount]], input[iter]);
	isReadingSubBag = 0;
	isReadingNumber = 1;
	subBagTotal[bagCount]++;
	iter += 1;
      }
      else if(input[iter + 1][strlen(input[iter + 1]) - 1] == '.') {
	//printf("reading subBagName endend: %s\n", input[iter]);
	strcat(subBag[bagCount][subBagTotal[bagCount]], input[iter]);
	subBagTotal[bagCount]++;
	isReadingSubBag = 0;
	isReadingBagName = 1;
	bagCount++;
	iter += 1;
      }
      else {
	strcat(subBag[bagCount][subBagTotal[bagCount]], input[iter]);
	strcat(subBag[bagCount][subBagTotal[bagCount]], " ");
      }
    }
    else {
      printf("should not reach here.\n");
    }
    iter++;
  }
  //printf("%d\n", inputCount);
  int ans = 0;
  //for(int i = 0; i < bagCount; i++) {
  //  if(doesItHaveShinyGold(i) == 1) {
  //    ans += 1;
  //  }
  for(int i = 0; i < bagCount; i++) {
    if(strcmp(bagName[i], "shiny gold") == 0) {
      ans = countBags(i);
      break;
    }
  }
  
    //printf("%s, %d\n", bagName[i], subBagTotal[i]);
    //for(int j = 0; j < subBagTotal[i]; j++) {
    //  printf("    %s %d\n", subBag[i][j], subBagCount[i][j]);
    //
  printf("ans: %d\n", ans);
  printf("%d", bagCount);
}
