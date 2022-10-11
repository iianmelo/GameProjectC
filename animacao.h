#ifndef animacao
#define animacao

#include "raylib.h"
#include "animacao.h"
#include "personagem.h"

typedef struct{
    int nitro; //se o nitro estiver ligado, fazer a animacao do nitro
    float angulo; 
    int direcao; //esse parametro dependera do valor que a funcao de movimentar o carro retornar
} spritesheetcarro;

void animarCarro(spritesheetcarro* carro_sheet, Texture2D textura_carro, Texture2D textura_nitro, veiculo carro);

#endif
