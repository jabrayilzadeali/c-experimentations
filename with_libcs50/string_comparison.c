#include "libcs50/cs50.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  string str1 = get_string("first string: ");
  string str2 = get_string("second string: ");

  for (int i = 0; i < strlen(str1); i++)
  {
    if (str1[i] == str2[i])
    {
      // printf("str1[%d]: %c == str2[%d]: %c \n", i, str1[i], i, str1[i]);
      continue;
    } 
    else 
    {
      printf("These are not equal\n");
      exit(0);
    }
  }
  printf("These strings are equal\n");
}
