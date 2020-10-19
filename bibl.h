#define LARMAPA 80
#define ALTMAPA 40

struct estr_bloco {
	char aparencia[2];
	int esqs;
	int fixo;
};

typedef struct estr_bloco bloco;

void preparar();
void limpartela();

void zerarmapa(bloco *mapa[LARMAPA][ALTMAPA]);
void atualizar(bloco *mapa[LARMAPA][ALTMAPA]);

int criarbloco(bloco *mapa[LARMAPA][ALTMAPA], int posx, int posy, char aparencia[2], int fixo, int seqescape);
void grav(bloco *mapa[LARMAPA][ALTMAPA]);

void criarlinha(bloco *mapa[LARMAPA][ALTMAPA], int posx, int posy, int comp, char vxh, char aparencia[2], int fixo, int seqescape);
