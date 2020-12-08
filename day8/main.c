#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct instra {
  char ins[10];
  int next;
  int isUsed;
} instra;

char input[2000][10];
int inputCount = 0;
instra instr[700];
int instrCount = 0;

int canStop() {
  int current = 0;
  int acc = 0;

  //printf("--------\n");
  //for(int i = 0; i < instrCount; i++) {
  //  printf("%s, %d\n", instr[i].ins, instr[i].next);
  //}
  //printf("--------\n");

  while(current < instrCount) {
    //printf("run %s %d\n", instr[current].ins, instr[current].next);
    if(instr[current].isUsed == 1) {
      for(int i=0;i<instrCount;i++) {
	instr[i].isUsed = 0;
      }
      //printf("instr[%d] is used stop\n", current);
      return 0;
    }
    if(strcmp(instr[current].ins, "nop") == 0) {
      instr[current].isUsed = 1;
      current += 1;
    }
    else if(strcmp(instr[current].ins, "acc") == 0) {
      acc += instr[current].next;
      instr[current].isUsed = 1;
      current += 1;
    }
    else if(strcmp(instr[current].ins, "jmp") == 0) {
      instr[current].isUsed = 1;
      current += instr[current].next;
    }
    else {
      printf("should not reach here.\n");
    }
  }
  return acc;
}

int main(void) {
  while(scanf("%s", input[inputCount++]) == 1);
  for(int i = 0; i < inputCount - 1; i+=2) {
    strcpy(instr[instrCount].ins, input[i]);
    instr[instrCount].next = atoi(input[i+1]);
    instr[instrCount].isUsed = 0;
    instrCount++;
  }
  int ans = 0;
  int changeIndex = 0;
  for(int i = 0; i < instrCount - 1; i++) {
    if(strcmp(instr[i].ins, "nop") == 0) {
      strcpy(instr[i].ins,"jmp");
      //printf("nop change %d, to %s\n", i, instr[i].ins);
      ans = canStop();
      if(ans == 0) {
	strcpy(instr[i].ins,"nop");
      }
      else {
	break;
      }
    }
    else if(strcmp(instr[i].ins, "jmp") == 0) {
      strcpy(instr[i].ins, "nop");
      //printf("jmp change %d, to %s\n", i, instr[i].ins);
      ans = canStop();
      if(ans == 0) {
	strcpy(instr[i].ins, "jmp");
      }
      else {
	break;
      }
    }
  }
  printf("ans: %d", ans);
  return 0;
}
