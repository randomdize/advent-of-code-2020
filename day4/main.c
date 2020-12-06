#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int findStr2InStr1(char*, char*);
int checkbyr(char*);
int checkiyr(char*);
int checkeyr(char*);
int checkhgt(char*);
int checkhcl(char*);
int checkecl(char*);
int checkpid(char*);

int main(void) {
  char input[2000][200];
  char passport [2000][200];
  int passcount = 0;
  int count = 0;
  int ans = 0;
  while(fgets(input[count++], 200, stdin) != NULL);
  for(int i = 0; i < count -1; i++) {
    if(strcmp(input[i], "\n") == 0) {
      passcount++;
    }
    else {
      if(input[i][strlen(input[i])-1] == '\n')
	input[i][strlen(input[i])-1] = ' ';
      strcat(passport[passcount], input[i]);
    }
  }
  //printf("passcount = %d\n", passcount);
  for(int i = 0; i < passcount + 1; i++) {
    //printf("%s\n", passport[i]);
    if(findStr2InStr1(passport[i], "byr:") == 0) {
      continue;
    }
    if(findStr2InStr1(passport[i], "iyr:") == 0) {
      continue;
    }
    if(findStr2InStr1(passport[i], "eyr:") == 0) {
      continue;
    }
    if(findStr2InStr1(passport[i], "hgt:") == 0) {
      continue;
    }
    if(findStr2InStr1(passport[i], "hcl:") == 0) {
      continue;
    }
    if(findStr2InStr1(passport[i], "ecl:") == 0) {
      continue;
    }
    if(findStr2InStr1(passport[i], "pid:") == 0) {
      continue;
    }
    ans = ans + 1;
  }
  printf("ans = %d\n", ans);
  return 0;
}

int findStr2InStr1(char* str1, char* str2) {
  //printf("find: %s\t %lu\t%lu\n", str2, strcspn(str1, str2), strlen(str1));
  //printf("%s, %s\n", str1, str2);
  char* ptr = strstr(str1, str2);
  if(ptr == NULL) {
    return 0;
  }
  else {
    char buf[100];
    int co = 0;
    ptr += 4;
    while(*ptr != '\0' && *ptr != ' ') {
      //printf("%c", *ptr);
      buf[co++] = *ptr;
      ptr++;
    }
    buf[co] = '\0';
    if(strcmp(str2, "byr:") == 0) return checkbyr(buf);
    if(strcmp(str2, "iyr:") == 0) return checkiyr(buf);
    if(strcmp(str2, "eyr:") == 0) return checkeyr(buf);
    if(strcmp(str2, "hgt:") == 0) return checkhgt(buf);
    if(strcmp(str2, "hcl:") == 0) return checkhcl(buf);
    if(strcmp(str2, "ecl:") == 0) return checkecl(buf);
    if(strcmp(str2, "pid:") == 0) return checkpid(buf);
    return 1;
  }
}

int checkbyr(char* input) {
  int value = atoi(input);
  if(value < 1920 || value > 2002) {
    printf("check byr failed . %s\n", input);
    return 0;
  }
  return 1;
}

int checkiyr(char* input) {
  int value = atoi(input);
  if(value < 2010 || value > 2020) {
    printf("checkiyr failed. %s\n", input);
    return 0;
  }
  return 1;
}

int checkeyr(char* input) {
  int value = atoi(input);
  if(value < 2020 || value > 2030) {
    printf("checkeyr failed. %s\n", input);
    return 0;
  }
  return 1;
}

int checkhgt(char* input) {
  char buff[100];
  int iscm = 0;
  int isin = 0;
  //printf("checkhgt: value  %lu\n", strlen(input));
  for(int i = 0; i < strlen(input); i++) {
    if(input[i] != 'i' && input[i] != 'c') {
      buff[i] = input[i];
    }
    else {
      if(input[i] == 'i') {
	isin = 1;
      }
      if(input[i] == 'c') {
	iscm = 1;
      }
      buff[i] = '\0';
      break;
    }
  }
  int value = atoi(buff);
  if(isin == 1) {
    if(value < 59 || value > 76) {
      printf("checkhgt failed. inch  %s\n", input);
      return 0;
    }
    return 1;
  }
  if(iscm == 1) {
    if(value < 150 || value > 193) {
      printf("checkhgt failed. cm  %s\n", input);
      return 0;
    }
    return 1;
  }
  printf("height should not reach here. %s\n", input);
  return 0;
}

int checkhcl(char* input) {
  if(strlen(input) != 7) {
    printf("checkhcl failed. %s\n", input);
    return 0;
  }
  if(input[0] != '#') return 0;
  for(int i = 1; i < 7; i++) {
    if((input[i] >= '0' && input[i] <= '9') || (input[i] >= 'a' && input[i] <= 'f')) {
      continue;
    }
    else {
      printf("checkhcl failed. %s\n", input);
      return 0;
    }
  }
  return 1;
}

int checkecl(char* input) {
  if(strcmp(input, "amb") == 0) return 1;
  if(strcmp(input, "blu") == 0) return 1;
  if(strcmp(input, "brn") == 0) return 1;
  if(strcmp(input, "gry") == 0) return 1;
  if(strcmp(input, "grn") == 0) return 1;
  if(strcmp(input, "hzl") == 0) return 1;
  if(strcmp(input, "oth") == 0) return 1;
  printf("checkecl failed. %s\n", input);
  return 0;
}

int checkpid(char* input) {
  if(strlen(input) != 9) return 0;
  for(int i=0; i<9;i++) {
    if(input[i] < '0' || input[i] > '9'){
      printf("checkpid failed. %s\n", input);
      return 0;
    }
  }
  return 1;
}
