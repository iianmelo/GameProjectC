#ifndef personagem
#define personagem

#include "raylib.h"
#include "personagem.h"
#include "animacao.h"
#include <math.h>
#include <stdlib.h>

typedef struct{
    float velocidade;
    Rectangle hitboxveiculo;
    Vector2 posicaoveiculo;

} veiculo;

void inicializaCarro(veiculo* carro);

int colidiu(veiculo carro, Rectangle* mapa, int numero_bordas);

int movimentarCarro1(veiculo* carro1, Rectangle mapa);

int movimentarCarro2(veiculo* carro2, Rectangle mapa);

int pegouNitro(spritesheetcarro* carro_sheet, veiculo* carro, Rectangle mapa, int numero_bordas, int numero_nitros);

#endif
