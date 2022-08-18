#include "../lib/BWT.h"
#include <stdlib.h>

void BWT_Construct(str_t *Str, str_t *BWT, uint_t N)
{
  int_str *Str_Aux = (int_str *)malloc(N * sizeof(int_str));
  int_sa *SA = (int_sa *)malloc(N * sizeof(int_sa));
  for (uint_t i = 0; i < N; i++)
  {
    SA[i] = 0;
    Str_Aux[i] = (int_str)Str[i];
  }
  DC3(Str_Aux, N, SA, 255);
  for (uint_t i = 0; i < N; i++)
  {
    uint_t sai = SA[i];
    BWT[i] = (!sai ? (Str[N - 1]) : (Str[sai - 1]));
  }
  free(SA);
  free(Str_Aux);
}

void BWT_Inverse_Construct(str_t *BWT, str_t *Str, uint_t N, uint_t Sigma)
{
  Sigma++;
  uint_t *Count = (uint_t *)malloc(Sigma * sizeof(uint_t));
  uint_t *LF = (uint_t *)malloc(Sigma * sizeof(uint_t));

  for (uint_t i = 0; i < Sigma; i++)
    Count[i] = 0;
  for (uint_t i = 0; i < N; i++)
    Count[BWT[i]]++;
  for (uint_t i = 0, val = 0; i < Sigma; i++)
  {
    val += Count[i];
    Count[i] = val - Count[i];
  }
  for (uint_t i = 0, j = 0; i < N; i++)
  {
    j = BWT[i];
    LF[Count[j]] = i;
    Count[j]++;
  }
  for (uint_t i = 0, j = LF[0]; i < N; i++)
  {
    j = LF[j];
    Str[i] = BWT[j];
  }

  free(Count);
  free(LF);
}