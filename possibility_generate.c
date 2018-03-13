#include <stdio.h>
#include <stdlib.h>


//#define MAXCOLORS 5
//#define MAXDEPTH 5


// Salvar possibilidades em matriz = MAXCOLORS^MAXDEPTH

void print(const int *v, const int size, int *line) {
  if (v != 0) {
    printf("%d   =  ", *line );
    for (int i = 0; i < size; i++) {
      printf("%4d", v[i] );
    }
    printf("\n");
  }
} // print


void visit(int *Value, int N, int k, int *line) {
  static int level = -1;
  level = level+1; 
  Value[k] = level;
  
  if (level == N) {
    *line = *line + 1;
    print(Value, N, line);
  }
  else
    for (int i = 0; i < N; i++)
      if (Value[i] == 0)
        visit(Value, N, i, line);

  level = level-1; 
  Value[k] = 0;
}


int main(int argc, char **argv) {

  if(argc != 2) {
    printf("Faltou argumento aí, meu filho!\n");
    return (-1);
  }


  // https://www.mathsisfun.com/combinatorics/combinations-permutations-calculator.html
  const int MC = atoi(argv[1]);
  //const int MD = 
  int Value[MC], line = 0;
  

  for (int i = 0; i < MC; i++) {
    Value[i] = 0;
  }
  
  visit(Value, MC, 0, &line);

  return 0;
}
