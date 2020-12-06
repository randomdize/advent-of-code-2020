#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
  char inputrange[1000][100];
  char inputrule[1000][100];
  char inputpayload[1000][100];
  int count = 0;
  int read = 1;
  while(read == 1) {
    read = scanf("%s", inputrange[count]);
    scanf("%s", inputrule[count]);
    scanf("%s", inputpayload[count]);
    count = count + 1;
  }

  int ans = 0;

  for(int i = 0; i < count - 1; i++) {
    char* pch;
    pch = strtok(inputrange[i], "-");
    int bottom = atoi(pch);
    pch = strtok(NULL, "-");
    int upper = atoi(pch);
    char token = inputrule[i][0];
    int charcount = 0;

    /*
    for(int j=0;j<strlen(inputpayload[i]);j++) {
      if(inputpayload[i][j] == token) {
	charcount = charcount + 1;
      }
      }
    if(charcount >= bottom && charcount <= upper) {
      ans = ans + 1;
      }*/
    printf("payload[%d] = %c, payload[%d] = %c, token = %c\n",
	     bottom - 1,
	     inputpayload[i][bottom - 1],
	     upper - 1,
	     inputpayload[i][upper - 1],
	     token);
    if((inputpayload[i][bottom - 1] == token || inputpayload[i][upper - 1] == token)
       && inputpayload[i][bottom - 1] != inputpayload[i][upper - 1]
       ) {
      
      ans = ans + 1;
    }
  }
	      
  printf("%d", ans);
  
  return 0;
}
