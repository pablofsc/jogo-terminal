void limpartela() {
	system("clear");
}

void preparar() {
	system("resize -s 41 160");
}

void zerarmapa(bloco *mapa[LARMAPA][ALTMAPA]) {
	int x, y;
	for(y = ALTMAPA; y >= 0; y--) {
		for(x = 0; x < LARMAPA; x++) {
			mapa[x][y] = NULL;
		}
	}
}

void atualizar(bloco *mapa[LARMAPA][ALTMAPA]) {
	//limpartela();
	
	int x, y;
	for(y = ALTMAPA - 1; y >= 0; y--) {
		for(x = 0; x < LARMAPA; x++) {
			if(mapa[x][y] == NULL) {
				printf("  ");
			}
			else {
				printf("\e[%im" "%c%c" "\e[0m", mapa[x][y]->esqs, mapa[x][y]->aparencia[0], mapa[x][y]->aparencia[1]);
			}
		}
		printf("\n");
	}
}

int criarbloco(bloco *mapa[LARMAPA][ALTMAPA], int posx, int posy, char aparencia[2], int fixo, int seqescape) {
	if(mapa[posx][posy] != NULL) {
		return(1);
	}
	mapa[posx][posy] = (bloco*) malloc(sizeof(bloco));
	
	mapa[posx][posy]->aparencia[0] = aparencia[0];
	mapa[posx][posy]->aparencia[1] = aparencia[1];
	mapa[posx][posy]->fixo = fixo;
	mapa[posx][posy]->esqs = seqescape;
	
	return(0);
}

void grav(bloco *mapa[LARMAPA][ALTMAPA]) {
	int x, y;
	for(y = 1; y < ALTMAPA; y++) {
		for(x = 0; x < LARMAPA; x++) {
			if(mapa[x][y] != NULL && mapa[x][y]->fixo == 0 && mapa[x][y - 1] == NULL) {
				mapa[x][y - 1] = mapa[x][y];
				mapa[x][y] = NULL;
			}
		}
	}
}

void criarlinha(bloco *mapa[LARMAPA][ALTMAPA], int posx, int posy, int comp, char vxh, char aparencia[2], int fixo, int seqescape) {
	int varx, vary;
	switch(vxh) {
		case 'h': // linha horizontal
			varx = 1;
			vary = 0;
			break;
			
		case 'v': // linha vertical
			varx = 0;
			vary = 1;
			break;
			
		case 'd': // linha diagonal
			varx = 1;
			vary = 1;
			break;
			
		default:
			return;
	}
	
	int x = posx;
	int y = posy;
	
	int comprimento = 0;
	while(comprimento < comp) {
		criarbloco(mapa, x, y, aparencia, fixo, seqescape);
		
		comprimento++;
		x += varx;
		y += vary;
	}
}
