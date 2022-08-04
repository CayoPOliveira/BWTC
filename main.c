#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BWT.h"

int main(int argc, char *argv[])
{
  FILE *file = fopen(argv[0], "r");
  fseek(file, 0, SEEK_END);
  uint_t N = ftell(file);
  rewind(file);
  str_t *str = (str_t *)malloc(N * sizeof(str_t));
  str_t *String_Original = (str_t *)malloc((N + 1) * sizeof(str_t));
  uint_t i = 0;
  while (file != EOF)
  {
    fscanf("%s", str);
    for (i; i < strlen(str); i++)
      String_Original[i] = (str_t)file[i];
  }
  String_Original[i] = (str_t)'$';
  N = i + 1;

  str_t *BWT = (str_t *)malloc(N * sizeof(str_t));
  str_t *String_New = (str_t *)malloc(N * sizeof(str_t));

  BWT_Construct(String_Original, BWT, N);
  BWT_Inverse_Construct(BWT, String_New, N, 256);

  int flag = 1;
  for (uint_t i = 0; i < N; i++)
  {
    if (String_Original[i] != String_New[i])
    {
      printf("Error: String from BWT [%d] is not a valid!", i);
      flag = 0;
    }
  }
  if (flag)
    printf("String from BWT is great!");

  free(BWT);
  free(String_New);
  return 0;
}