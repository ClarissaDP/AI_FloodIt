OBJ=floodIt_solver.o funcoes_arvore.o funcoes_mapa.o funcoes_matriz.o funcoes_programa.o

all: inicial floodIt_solver clean


inicial: 
	@echo "Iniciando"

floodIt_solver: $(OBJ)
	@gcc -o floodIt_solver $(OBJ)

floodIt_solver.o: floodIt_solver.h floodIt_solver.c
	@gcc -c floodIt_solver.c -Wall
funcoes_arvore.o: floodIt_solver.h funcoes_arvore.c
	@gcc -c funcoes_arvore.c
funcoes_mapa.o: floodIt_solver.h funcoes_mapa.c
	@gcc -c funcoes_mapa.c
funcoes_matriz.o: floodIt_solver.h funcoes_matriz.c
	@gcc -c funcoes_matriz.c
funcoes_programa.o: floodIt_solver.h funcoes_programa.c
	@gcc -c funcoes_programa.c

clean:
	@echo "Finalizando"
	@rm -rf *.o

clean-full:
	@echo "Apagando"
	@rm -rf *.o
	@rm floodIt_solver

