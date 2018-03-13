#include "floodIt_solver.h"


// Funções de matriz

// m = Matriz com o estado atual da matriz
// aux = Matriz de 1's e 0's que sera utilizada a cada interação, cada um dos filhos tera uma matriz copia da do pai

// x, y = coordenadas da celula que contem a cor que deseja contar
int contaCores(tmapa *aux, int x, int y, int color) {
  int right, left, up, down;

  if ((m.mapa[x][y] == color) && (!aux->mapa[x][y])) {
    aux->mapa[x][y] = 2;
  
    if(y+1 < m.ncolunas) {
      if ((m.mapa[x][y+1] == color) && (!aux->mapa[x][y+1])) 
        right = contaCores(aux, x, y+1, color);
      else
        right = 0;
    }
    else
      right = 0;

    if(y-1 >= 0) {
      if ((m.mapa[x][y-1] == color) && (!aux->mapa[x][y-1])) 
        left = contaCores(aux, x, y-1, color);
      else
        left = 0;
    }
    else
      left = 0;

    if(x-1 >= 0) {
      if ((m.mapa[x-1][y] == color) && (!aux->mapa[x-1][y])) 
        up = contaCores(aux, x-1, y, color);
      else
        up = 0;
    }
    else
      up = 0;
    
    if(x+1 < m.nlinhas) {
      if ((m.mapa[x+1][y] == color) && (!aux->mapa[x+1][y])) 
        down = contaCores(aux, x+1, y, color);
      else
        down = 0;
    }
    else
      down = 0;

    return 1 + right + left + up + down;
  } else
    return 0;
}


int varreVizinhaca(tmapa *aux, int x, int y, int color) {
  int right, left, up, down;

  aux->mapa[x][y] = 2;

  if(y+1 < m.ncolunas) {
    if (aux->mapa[x][y+1] == 0) 
      right = contaCores(aux, x, y+1, color);
    else if (aux->mapa[x][y+1] == 1)
      right = varreVizinhaca(aux, x, y+1, color);
    else
      right = 0;
  }
  else
    right = 0;

  if(y-1 >= 0) {
    if (aux->mapa[x][y-1] == 0)
      left = contaCores(aux, x, y-1, color);
    else if (aux->mapa[x][y-1] == 1)
      left = varreVizinhaca(aux, x, y-1, color);
    else
      left = 0;
  }
  else
    left = 0;

  if(x-1 >= 0) {
    if (aux->mapa[x-1][y] == 0)
      up = contaCores(aux, x-1, y, color);
    else if (aux->mapa[x-1][y] == 1)
      up = varreVizinhaca(aux, x-1, y, color);
    else
      up = 0;
  }
  else
    up = 0;

  if(x+1 < m.nlinhas) {
    if (aux->mapa[x+1][y] == 0)
      down = contaCores(aux, x+1, y, color);
    else if (aux->mapa[x+1][y] == 1)
      down = varreVizinhaca(aux, x+1, y, color);
    else
      down = 0;
  }
  else
    down = 0;

  return 1 + right + left + up + down; 
}


void iniciaFiltro(tmapa *aux, int x, int y, int color, int *nvalor) {
  aux->mapa[x][y] = 1;
  *nvalor = *nvalor + 1;

  if(y+1 < m.ncolunas) {
    if (m.mapa[x][y+1] == color && !aux->mapa[x][y+1]) 
      iniciaFiltro(aux, x, y+1, color, nvalor);
  }

  if(y-1 >= 0) {
    if (m.mapa[x][y-1] == color && !aux->mapa[x][y-1]) 
      iniciaFiltro(aux, x, y-1, color, nvalor);
  }

  if(x-1 >= 0) {
    if (m.mapa[x-1][y] == color && !aux->mapa[x-1][y]) 
      iniciaFiltro(aux, x-1, y, color, nvalor);
  }

  if(x+1 < m.nlinhas) {
    if (m.mapa[x+1][y] == color && !aux->mapa[x+1][y]) 
      iniciaFiltro(aux, x+1, y, color, nvalor);
  }

  return;
}


void zeraFiltro(tmapa *aux) {
  int i, j;

  aux->nlinhas = m.nlinhas;
  aux->ncolunas = m.ncolunas;
  aux->ncores = m.ncores;
  aux->mapa = (int**) malloc(m.nlinhas * sizeof(int*));

  for ( i = 0; i < m.nlinhas ; ++i ) {
    aux->mapa[i] = (int*) malloc(m.ncolunas * sizeof(int));

    for ( j = 0; j < m.ncolunas ; ++j )
      aux->mapa[i][j] = 0;
  }
}


tmapa copiaFiltro(tmapa filtro_velho) {
  int i, j;
  tmapa aux;
  
  aux.nlinhas = filtro_velho.nlinhas;
  aux.ncolunas = filtro_velho.ncolunas;
  aux.ncores = filtro_velho.ncores;
  aux.mapa = (int**) malloc(m.nlinhas * sizeof(int*));

  for ( i = 0; i < m.nlinhas ; ++i ) {
    aux.mapa[i] = (int*) malloc(m.ncolunas * sizeof(int));

    for ( j = 0; j < m.ncolunas ; ++j ) {
      if ( filtro_velho.mapa[i][j] != 0 ) 
        aux.mapa[i][j] = 1;
      else
        aux.mapa[i][j] = filtro_velho.mapa[i][j];
    }
  }

  return aux;
}

