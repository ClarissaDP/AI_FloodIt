#include "floodIt_solver.h"


// Funções de programa

int checaFinal() {
  int i, j;
  int cor = m.mapa[0][0];
  int cores[m.ncores];
  int is_over = 1;

  for(i = (m.nlinhas-1); is_over && i >= 0; --i)
    for(j = (m.ncolunas-1); is_over && j >= 0; --j) {
      if( m.mapa[i][j] != cor ) 
        is_over = 0;
    }
  
  return is_over;
}


int *criaSequencia() {
  int *sequencia;
  
  if(!(sequencia = (int*)malloc(m.nlinhas*m.ncolunas*sizeof(int))))
    return 0;

  return sequencia;
}


void imprimeSequencia(int *seq, int fim) {
  int i;
  printf("%d\n", fim);
  
  for ( i = 0; i < fim; ++i )
    printf("%d ", seq[i]);
  
  printf("\n");
  return;
}

