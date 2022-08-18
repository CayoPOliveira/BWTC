#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib/BWT.h"

#define DEBUG1 1

int main(int argc, char *argv[])
{
  FILE *file = fopen(argv[1], "r");
  if (file == NULL)
  {
    printf("Problemas na abertura do arquivo '%s'\n", argv[1]);
    return 0;
  }

  fseek(file, 0, SEEK_END);
  uint_t N = ftell(file);
  rewind(file);

  str_t *str = (str_t *)malloc(N * sizeof(str_t));
  str_t *BWT = (str_t *)malloc(N * sizeof(str_t));
  str_t *String_Original = (str_t *)malloc((N + 1) * sizeof(str_t));
  str_t *String_New = (str_t *)malloc(N * sizeof(str_t));

  // String_Original[0] = '\0';
  while (!feof(file))
  {
    fgets(str, N, file);
    strcat(String_Original, str);
    fgets(str, N, file);
  }
  fclose(file);

  N = strlen(String_Original);
  String_Original[N - 1] = (str_t)'$';
  N++;

  BWT_Construct(String_Original, BWT, N);
  BWT_Inverse_Construct(BWT, String_New, N, 256);

  if (strcmp(String_Original, String_New))
    printf("Error: String from BWT is not a valid!\norig: %s\nnovo: %s\n", String_Original, String_New);
  else
    printf("String from BWT is great!\n");

  free(str);
  free(String_Original);
  free(String_New);
  free(BWT);
  return 0;
}