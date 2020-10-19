// 19/10/2020

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "bibl.h"
#include "func.h"

bloco *matriz[LARMAPA][ALTMAPA]; // mapa de ponteiros que podem apontar para blocos ou nao

int main() {
	preparar();
	zerarmapa(matriz);
	
	criarlinha(matriz, 0, 1, LARMAPA, 'h', "//", 1, 42);
	criarlinha(matriz, 0, 0, LARMAPA, 'h', "  ", 1, 42);
	criarlinha(matriz, 30, 4, 30, 'd', "  ", 1, 44);
	criarlinha(matriz, 20, 30, 7, 'v', "  ", 0, 45);
	criarlinha(matriz, 35, 35, 10, 'h', "[]", 0, 0);
	
	//    mapa    x   y  apar. fix esq
	criarbloco(matriz, 10, 35, "  ", 0, 47);
	criarbloco(matriz, 10, 30, "  ", 1, 41);
	
	criarbloco(matriz, 15, 37, "  ", 0, 47);
	criarbloco(matriz, 15, 23, "  ", 1, 41);
	
	criarbloco(matriz, 20, 33, "  ", 0, 47);
	criarbloco(matriz, 23, 25, "  ", 1, 41);
	
	criarbloco(matriz, 20, 3, "  ", 1, 41);
	
	srand(time(NULL));
	int i;
	for(i = 0; i <= 1000; i++) {
		criarbloco(matriz, rand() % LARMAPA, rand() % ALTMAPA, "  ", 0, 47);
	}
	
	
	
	for(;;) {
		atualizar(matriz);
		grav(matriz);
		usleep(50000); // 20 FPS se o resto fosse instantâneo
	}
}
