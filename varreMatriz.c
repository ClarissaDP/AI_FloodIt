#include <stdio.h>
#define MAX 10

// Matriz com o estado atual da matriz
int m[MAX][MAX];

// Matriz de 1's e 0's que sera utilizada a cada interação, cada um dos filhos tera uma matriz copia da do pai
int aux[MAX][MAX];

// X, Y = coordenadas da celula que contem a cor que deseja contar
int contaCores(int aux[MAX][MAX], int x, int y, int color) {
	int right, left, up, down;

	if ((m[x][y] == color) && (!aux[x][y])) {
		aux[x][y] = 2;
	
		// right = y+1 >= MAX ? 0 : m[x][y+1] == colors[index] ? contaCores(x, y+1, index) : ((index + 1 <=MAX) && (m[x][y+1] == colors[index + 1])) ? contaCores(x, y+1, index+1) : 0;
		if(y+1 < MAX) {
			if ((m[x][y+1] == color) && (!aux[x][y+1])) 
				right = contaCores(aux, x, y+1, color);
			else
				right = 0;
		}
		else
			right = 0;

		if(y-1 >= 0) {
			if ((m[x][y-1] == color) && (!aux[x][y-1])) 
				left = contaCores(aux, x, y-1, color);
			else
				left = 0;
		}
		else
			left = 0;

		if(x-1 >= 0) {
			if ((m[x-1][y] == color) && (!aux[x-1][y])) 
				up = contaCores(aux, x-1, y, color);
			else
				up = 0;
		}
		else
			up = 0;
		
		if(x+1 < MAX) {
			if ((m[x+1][y] == color) && (!aux[x+1][y])) 
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

int varreVizinhaca(int aux[MAX][MAX], int x, int y, int color) {
	int right, left, up, down;

	aux[x][y] = 2;

	if(y+1 < MAX) {
		if (aux[x][y+1] == 0) 
			right = contaCores(aux, x, y+1, color);
		else if (aux[x][y+1] == 1)
			right = varreVizinhaca(aux, x, y+1, color);
		else
			right = 0;
	}
	else
		right = 0;

	if(y-1 >= 0) {
		if (aux[x][y-1] == 0)
			left = contaCores(aux, x, y-1, color);
		else if (aux[x][y-1] == 1)
			left = varreVizinhaca(aux, x, y-1, color);
		else
			left = 0;
	}
	else
		left = 0;

	if(x-1 >= 0) {
		if (aux[x-1][y] == 0)
			up = contaCores(aux, x-1, y, color);
		else if (aux[x-1][y] == 1)
			up = varreVizinhaca(aux, x-1, y, color);
		else
			up = 0;
	}
	else
		up = 0;

	if(x+1 < MAX) {
		if (aux[x+1][y] == 0)
			down = contaCores(aux, x+1, y, color);
		else if (aux[x+1][y] == 1)
			down = varreVizinhaca(aux, x+1, y, color);
		else
			down = 0;
	}
	else
		down = 0;

	return 1 + right + left + up + down; 
}

// // Descomentar para testar.
// int main(int argc, char const *argv[])
// {
// 	// BEGIN regras de montagem de matriz
// 	for(int i = 0; i < MAX; i++) {
// 		for (int j = 0; j < MAX; j++) {
// 			m[i][j] = 1;
// 			aux[i][j] = 0;
// 		}
// 	}

// 	for (int i = 0; i < MAX; ++i) {
// 		m[i][5] = 2;
// 		m[i][4] = 3;
// 		m[4][i] = 1;
// 		aux[i][5] = 1;
// 		m[i][i] = 1;
// 		aux[i][i] = 0;
// 	}

// 	for(int i = 0; i < MAX; i++) {
// 		for (int j = 0; j < MAX; j++) {
// 			printf("%d", m[i][j]);
// 		}
// 		printf("\n");
// 	}

// 	// END regras de  montagem de matriz

// 	for(int i = 0; i < MAX; i++) {
// 		for (int j = 0; j < MAX; j++) {
// 			printf("%d", aux[i][j]);
// 		}
// 		printf("\n");
// 	}

// 	printf("%d\n", varreVizinhaca(aux, 0, 5, 3));

// 	for(int i = 0; i < MAX; i++) {
// 		for (int j = 0; j < MAX; j++) {
// 			printf("%d", aux[i][j]);
// 		}
// 		printf("\n");
// 	}

// 	return 0;
// }