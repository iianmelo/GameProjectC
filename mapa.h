#include "raylib.h"
#include "personagem.h"
#include "animacao.h"

Texture2D abrirMapa();

bool checarLimitesDaCamera();

int colidiu(veiculo carro, Rectangle* mapa, int numero_bordas);

