#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 105

// --- Structs ---
typedef struct {
  int nlinhas;
  int ncolunas;
  int ncores;
  int **mapa;
} tmapa;

typedef struct no *ApNo;

typedef struct no {
  int corAtual;
  int valor;
  tmapa filtro;
  ApNo filhos[11];
} nodo;


// --- Globais ---
tmapa m;
ApNo arv;
int caminho[MAX];
int MC;


// Funcoes de mapa 
void carregaMapa();
void pinta(int, int, int, int);
void pintaMapa(int);

// Funções de programa
int checaFinal();
int *criaSequencia();
void imprimeSequencia(int *, int);

// Funções de matriz
int contaCores(tmapa *, int, int, int);
int varreVizinhaca(tmapa *, int, int, int);
void iniciaFiltro (tmapa *, int, int, int, int *);
void zeraFiltro (tmapa *);
tmapa copiaFiltro (tmapa);

// Funções de arvore
int profundidade(int linhas, int colunas, int cores);
ApNo iniciaNodo(ApNo);
ApNo criaNodo (int, int);
ApNo geraArvore(int, int);
void liberaArvore (ApNo, ApNo);

// Funções de fluxo # main
ApNo escolheCor(ApNo, int);
int resolveJogo(int, int *, int);

