#include "floodIt_solver.h"


// Fluxo do programa

ApNo escolheCor(ApNo n, int valor_pai) {
  int i, maior;
  ApNo maior_n, tmp;

  n->valor = varreVizinhaca(&n->filtro, 0, 0, n->corAtual);

  if (n->filhos[0] == NULL && n->filhos[1] == NULL)
    return n;
  
  maior = 0;
  maior_n = n->filhos[0];

  for (i=0 ; i < (MC-1) ; ++i)
    if ((i+1) != n->corAtual) {
      n->filhos[i]->filtro = copiaFiltro(n->filtro);
      tmp = escolheCor(n->filhos[i], n->valor);
      n->filhos[i]->valor = tmp->valor;

      if (maior < n->filhos[i]->valor) {
        maior = n->filhos[i]->valor; 
        maior_n = n->filhos[i];
      }
    }

  return maior_n;
}


int resolveJogo(int fim, int *sequencia, int t) {
  int final_jogo = 0;
  ApNo test;

  while(!final_jogo && t) {
    if (!(arv = (ApNo) malloc(sizeof(nodo)))) {
      printf("Erro na alocação.");

      return 0;
    }
    arv = geraArvore((m.mapa[0][0]-1), t);

    zeraFiltro (&arv->filtro);
    iniciaFiltro (&arv->filtro, 0, 0, m.mapa[0][0], &arv->valor);

    arv->valor = varreVizinhaca(&arv->filtro, 0, 0, m.mapa[0][0]);
    test = escolheCor(arv, arv->valor);
    sequencia[fim++] = test->corAtual;
    
    pintaMapa(test->corAtual);

    final_jogo = checaFinal(&m);

    if ( test->valor == m.nlinhas*m.ncolunas ) 
      --t;

    liberaArvore (arv, arv);
  }

  return fim;

}


/* ******************************************************************************* */
/*                                       MAIN                                      */
/* ******************************************************************************* */

int main(int argc, char **argv) {
  int fim = 0, *sequencia, t;
  
  carregaMapa();

  t = profundidade(m.nlinhas, m.ncolunas, m.ncores);
  sequencia = criaSequencia();

  fim = resolveJogo(fim, sequencia, t);
  imprimeSequencia(sequencia, fim);

  return 0;
}

