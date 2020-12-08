#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Bag {
  char Name[100];
  char* SubBag[200];
  int SubBagCount[300];
  int SubBagTotal;
  int NoOtherBag;
} Bag;

int doesItHaveShinyBag(Bag *bag, Bag allBag[300], int bagCount) {
  printf("%s\n", bag->Name);
  if(strcmp(bag->Name, "shiny gold") == 0) return 1;
  if(bag->SubBagTotal == 0) return 0;
  int haveShinyBag = 0;
  for(int i = 0; i < bag->SubBagTotal; i++) {
    for(int j = 0; j < bagCount; j++) {
      //printf("subBag: %s, allBag: %s\n", bag->SubBag[i], allBag[j].Name);
      if(strcmp(bag->SubBag[i], allBag[j].Name) == 0) {
	if(doesItHaveShinyBag(&allBag[j], allBag, bagCount) == 1) {
	  printf("%s have shiny gold.\n", allBag[j].Name);
	  return 1;
	}
	return 0;
      }
    }
  }
  printf("%s, should not reach here\n", bag->Name);
  return 0;
}


int main(void) {
  char input[600][100];
  char inputCount = 0;
  ///Bag bg[500];
  int bagCount = 0;
  while(scanf("%s", input[inputCount++]) == 1);
  for(int i = 0; i < inputCount - 1; i++) {
    printf("%s\n", input[i]);
  }
  /*
  while(fgets(input[inputCount++], 200, stdin) != NULL);
  ///printf("inputCount %d\n", inputCount);
  for(int i = 0; i < inputCount+1; i++) {
    // find "contain" location.
    char* containLocation = strstr(input[i], "contain");
    int containIndex = containLocation - input[i];
    strncpy(bg[bagCount].Name, input[i], containIndex -6);
    if(strstr(input[i], "no other bags") == NULL) {
      // string from point after contain to read
      char* ptr = containLocation + 8;
      char buffer[100];
      int bufferCount = 0;
      int isReadingNumber = 1;
      int isReadingBag = 0;
      while(*ptr != '.') {
	//printf("reading: %c\n", *ptr);
	buffer[bufferCount++] = *ptr++;
	if(isReadingNumber == 1) {
	  if(*ptr == ' ') {
	    buffer[bufferCount] = '\0';
	    //printf("copy buffer number:%s\n", buffer);

	    bg[bagCount].SubBagCount[bg[bagCount].SubBagTotal] = atoi(buffer);
	    isReadingNumber = 0;
	    bufferCount = 0;
	    ptr += 1;
	    //for(int z=0; z<100; z++) buffer[z] = '\0';
	    //printf("bg number: %d\n", bg[bagCount].SubBagCount[bg[bagCount].SubBagTotal]);
	  }
	}
	else {
	  if(*ptr == '.' || *ptr == ',') {
	    buffer[bufferCount] = '\0';
	    //printf("copy buffer:%s/bufferCount=%d\n", buffer, bufferCount);
	    strncpy(bg[bagCount].SubBag[bg[bagCount].SubBagTotal], buffer, bufferCount - 4);
	    //bg[bagCount].SubBag[bg[bagCount].SubBagTotal][bufferCount - 2] = '\0';
	    isReadingNumber = 1;
	    bg[bagCount].SubBagTotal += 1;
	    bufferCount = 0;
	    if(*ptr == '.') break;
	    ptr += 1;
	    //for(int z=0; z<100; z++) buffer[z] = '\0';
	  }
	}
	
      }
    }
    else {
      bg[i].NoOtherBag = 1;
    }
    //printf("input %s", input[i]);
    //printf("containIndex %d\n", containIndex);
    bagCount++;
  }
  for(int i = 0; i < bagCount; i++) {
    //printf("%s Contain ", bg[i].Name);
    for(int j = 0; j < bg[i].SubBagTotal; j++) {
      if(bg[i].SubBag[j][strlen(bg[i].SubBag[j]) - 1] == ' ') {
	bg[i].SubBag[j][strlen(bg[i].SubBag[j]) - 1] = '\0';
      }
      //printf("%d %s,", bg[i].SubBagCount[j] ,bg[i].SubBag[j]);
    }
    //printf("\n");
  }
  int ans = 0;
  for(int i = 0; i < bagCount; i++) {
    //printf("bg name: %s\n", bg[i].Name);
    //doesItHaveShinyBag(&bg[i], bg, bagCount);
    //if(doesItHaveShinyBag(&bg[i], bg, bagCount) == 1) {
    //  ans += 1;
    //}
  }
  printf("bagCount %d ", bagCount);
  printf("ans = %d", ans);*/
}

