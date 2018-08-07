#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char * str) {
  if (str == NULL) {
    return;
  }
  //find the length of the string
  int len = 0;
  //printf("Before ++, str: %d\n", *str);
  while (*str != 0) {
    len++;
    str++;
  }
  //printf("Before reset, str: %d\n", *str);
  // reset the pointer to the beginning of the string
  str -= len;
  //printf("After reset, str: %d\n", *str);

  // loop over half the string
  // swapping the ith value with the (len-i)th value
  for (int i=0; i<len/2; i++) {
    char tmp = str[i];
    //printf("i: %d and tmp: %c\n", i, tmp);
    //printf("str[len-i] = %c\n", str[len-i-1]);
    str[i] = str[len-i-1];
    str[len-i-1] = tmp;
  }
}

int main(void) {
  char str0[] = "";
  char str1[] = "123";
  char str2[] = "abcd";
  char str3[] = "Captain's log, Stardate 42523.7";
  char str4[] = "Hello, my name is Inigo Montoya.";
  char str5[] = "You can be my wingman anyday!";
  char str6[] = "Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!";
  char * array[] = {str0, str1, str2, str3, str4, str5, str6};
  for (int i = 0; i < 7; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
  }
  return EXIT_SUCCESS;
}
