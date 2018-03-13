#include "floodIt_solver.h"


// Funções de arvore

int profundidade(int linhas, int colunas, int cores) {
    int aux = linhas * colunas;

    switch (cores) {
        case 10:
        case 9:
        case 8:
        case 7:
        case 6:
            if (aux <= 900)
                return 6;
            else
                return 4;
            break;

        case 5:
        case 4:
            if (aux <= 900)
                return 9;
            else
                return 7;
            break;

        case 3:
        case 2:
            if (aux < 900)
                return 4;
            else
                return 13;
            break;

        default:
            return 4;
    }
}


ApNo iniciaNodo(ApNo novo) {
  int i;

  for ( i = 0; i < MC ; ++i )
    novo->filhos[i] = NULL;

  return novo;
}


ApNo criaNodo(int c, int v) {
  ApNo novo;

  if (!(novo = (ApNo) malloc(sizeof(nodo))))
    return NULL;   

  novo->corAtual = (c+1);
  novo->valor = v;
  novo->filtro.mapa = NULL;

  return iniciaNodo(novo);
}


ApNo geraArvore(int k, int cmd) { 
  int i;
  ApNo atual;

  if (cmd == 0) 
    return NULL;

  atual = criaNodo(k, 0);

  for(i = 0; i < (MC-1); ++i) 
    if (i != k)
      atual->filhos[i] = geraArvore(i, (cmd-1));
    else
      atual->filhos[i] = NULL;

  return atual;
}


void liberaArvore(ApNo n, ApNo raiz) {
  int i;

  if (n == NULL)
    return;

  for (i=0 ; i < MC-1 ; ++i)
      liberaArvore(n->filhos[i], raiz);

  if (n != raiz) {
    if ( n->filtro.mapa ) {
      for (i = 0; i < n->filtro.nlinhas; i++)
        free(n->filtro.mapa[i]);

      free(n->filtro.mapa);
    }

    return free(n);
  }

  return;
}

