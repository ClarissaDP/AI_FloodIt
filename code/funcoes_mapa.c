#include "floodIt_solver.h"


// Funcoes de mapa

void carregaMapa() {
  int i, j;

  scanf("%d", &(m.nlinhas));
  scanf("%d", &(m.ncolunas));
  scanf("%d", &(m.ncores));

  MC = m.ncores + 1;
  m.mapa = (int**) malloc(m.nlinhas * sizeof(int*));

  for(i = 0; i < m.nlinhas; i++) {
    m.mapa[i] = (int*) malloc(m.ncolunas * sizeof(int));

    for(j = 0; j < m.ncolunas; j++)
      scanf("%d", &(m.mapa[i][j]));
  }
}


void pinta(int l, int c, int fundo, int cor) {
  m.mapa[l][c] = cor;

  if(l < m.nlinhas - 1 && m.mapa[l+1][c] == fundo)
    pinta(l+1, c, fundo, cor);

  if(c < m.ncolunas - 1 && m.mapa[l][c+1] == fundo)
    pinta(l, c+1, fundo, cor);

  if(l > 0 && m.mapa[l-1][c] == fundo)
    pinta(l-1, c, fundo, cor);

  if(c > 0 && m.mapa[l][c-1] == fundo)
    pinta(l, c-1, fundo, cor);
}


void pintaMapa(int cor) {
  if(cor == m.mapa[0][0])
    return;

  pinta(0, 0, m.mapa[0][0], cor);
}

