#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct {
  int nlinhas;
  int ncolunas;
  int ncores;
  int **mapa;
} tmapa;

void gera_mapa(tmapa *m, int semente) {
  int i, j;

  if(semente < 0)
    srand(time(NULL));  
  else
    srand(semente);  
  m->mapa = (int**) malloc(m->nlinhas * sizeof(int*));
  for(i = 0; i < m->nlinhas; i++) {
    m->mapa[i] = (int*) malloc(m->ncolunas * sizeof(int));
    for(j = 0; j < m->ncolunas; j++)
      m->mapa[i][j] = 1 + rand() % m->ncores;
  }
}

void carrega_mapa(tmapa *m) {
  int i, j;

  scanf("%d", &(m->nlinhas));
  scanf("%d", &(m->ncolunas));
  scanf("%d", &(m->ncores));
  m->mapa = (int**) malloc(m->nlinhas * sizeof(int*));
  for(i = 0; i < m->nlinhas; i++) {
    m->mapa[i] = (int*) malloc(m->ncolunas * sizeof(int));
    for(j = 0; j < m->ncolunas; j++)
      scanf("%d", &(m->mapa[i][j]));
  }
}

void mostra_mapa(tmapa *m) {
  int i, j;

  printf("%d %d %d\n", m->nlinhas, m->ncolunas, m->ncores);
  for(i = 0; i < m->nlinhas; i++) {
    for(j = 0; j < m->ncolunas; j++)
      if(m->ncores > 10)
	      printf("%02d ", m->mapa[i][j]);
      else
	      printf("%d ", m->mapa[i][j]);
    printf("\n");
  }
}

void mostra_mapa_cor(tmapa *m) {
  int i, j;
  char* cor_ansi[] = { "\x1b[0m",
		       "\x1b[31m", "\x1b[32m", "\x1b[33m",
		       "\x1b[34m", "\x1b[35m", "\x1b[36m",
		       "\x1b[37m", "\x1b[30;1m", "\x1b[31;1m",
		       "\x1b[32;1m", "\x1b[33;1m", "\x1b[34;1m",
		       "\x1b[35;1m", "\x1b[36;1m", "\x1b[37;1m" };

  if(m->ncores > 15) {
    mostra_mapa(m);
    return;
  }
  printf("%d %d %d\n", m->nlinhas, m->ncolunas, m->ncores);
  for(i = 0; i < m->nlinhas; i++) {
    for(j = 0; j < m->ncolunas; j++)
      if(m->ncores > 10)
	printf("%s%02d%s ", cor_ansi[m->mapa[i][j]], m->mapa[i][j], cor_ansi[0]);
      else
	printf("%s%d%s ", cor_ansi[m->mapa[i][j]], m->mapa[i][j], cor_ansi[0]);
    printf("\n");
  }
}

void pinta(tmapa *m, int l, int c, int fundo, int cor) {
  m->mapa[l][c] = cor;
  if(l < m->nlinhas - 1 && m->mapa[l+1][c] == fundo)
    pinta(m, l+1, c, fundo, cor);
  if(c < m->ncolunas - 1 && m->mapa[l][c+1] == fundo)
    pinta(m, l, c+1, fundo, cor);
  if(l > 0 && m->mapa[l-1][c] == fundo)
    pinta(m, l-1, c, fundo, cor);
  if(c > 0 && m->mapa[l][c-1] == fundo)
    pinta(m, l, c-1, fundo, cor);
}

void pinta_mapa(tmapa *m, int cor) {
  if(cor == m->mapa[0][0])
    return;
  pinta(m, 0, 0, m->mapa[0][0], cor);
}

int checa_final(tmapa *m, int *prox) {
  int i, j;
  int cor = m->mapa[0][0];
  
  int cores[m->ncores];
  int flag = 1, maior = 0, ind_maior = 0;

  for(i = 0; i < m->ncores; i++)
      cores[i] = 0;
    
  for(i = 0; i < m->nlinhas; i++)
    for(j = 0; j < m->ncolunas; j++) {
      cores[m->mapa[i][j] - 1]++;

      if( m->mapa[i][j] != cor ) 
        flag = 0;
        //return 0;
      }
  
  
  // Verificar se é vizinho


  //printf("Atual: %d\n", cor);
  //printf("Cores: \n");
  for(i = 0; i < m->ncores; i++) {
      //printf("%d => %d\n", (i+1), cores[i]); 
      if ( cores[i] > maior && (i+1) != cor ) {
        maior = cores[i];
      ind_maior = (i+1);
      }
  }
  *prox = ind_maior;

  //printf("prox %d\n", *prox);
  //return 1;
  return flag;
}

int *cria_sequencia(tmapa *m) {
  int *sequencia;
  
  if(!(sequencia = (int*)malloc(m->nlinhas*m->ncolunas*sizeof(int))))
    return 0;
  return sequencia;
}

void printa_sequencia(int *seq, int fim) {
  int i;
  printf("\n%d\n", fim);
  
  for ( i = 0; i < fim; ++i ) {
    printf("%d ", seq[i]);
  }
  printf("\n");
  return;
}


int main(int argc, char **argv) {
  int cor;
  tmapa m;
  int semente;
  int final_jogo = 0;
  int *sequencia, fim = 0;
  int prox;

  if(argc < 4 || argc > 5) {
    printf("uso: %s <numero_de_linhas> <numero_de_colunas> <numero_de_cores> [<semente_aleatoria>]\n", argv[0]);
    exit(1);
  }

  m.nlinhas = atoi(argv[1]);
  m.ncolunas = atoi(argv[2]);
  m.ncores = atoi(argv[3]);

  if(argc == 5)
    semente = atoi(argv[4]);
  else
    semente = -1;
  gera_mapa(&m, semente);
  //mostra_mapa_cor(&m);  
  mostra_mapa(&m);
  final_jogo = checa_final(&m, &prox);

  sequencia = cria_sequencia(&m);
  if (!sequencia) 
    return 0;

  cor = prox;
  //scanf("%d", &cor);
/*  while(cor > 0 && cor <= m.ncores && !final_jogo) {
    pinta_mapa(&m, cor);
    //mostra_mapa_cor(&m); // para mostrar sem cores use mostra_mapa(&m);
    sequencia[fim++] = cor;
    final_jogo = checa_final(&m, &prox);
    if ( !final_jogo )
      //scanf("%d", &cor);
      cor = prox;
    
  }
  
  printa_sequencia(sequencia, fim);
*/

  return 0;
}
