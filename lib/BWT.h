#ifndef BWT_H
#define BWT_H

#include "DC3.h"

typedef char str_t;

/*
  BWT_Construct() aplica a transformada de Burrows-Wheeller a um array e retorna o resultado;

  @param *Str  String que será aplicada a transformada
  @param *BWT  Buffer que guardará a transformada
  @param N    Tamanho do array
*/
void BWT_Construct(str_t *Str, str_t *BWT, uint_t N);

/*
  BWT_Inverse_Construct() aplica a transformada inversa de Burrows-Wheeller para gerar a string geradora;

  @param *BWT    String já aplicada a transformada
  @param *Str    Buffer que guardará a string geradora
  @param N      Tamanho do array
  @param Sigma  Máximo valor do vetor (exemplo: maximo valor da ASCII - 256)

*/
void BWT_Inverse_Construct(str_t *BWT, str_t *Str, uint_t N, uint_t Sigma);

#endif