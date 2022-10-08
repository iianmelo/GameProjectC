#ifndef personagem
#define personagem

#include "raylib.h"
#include "personagem.h"
#include <math.h>
#include <stdlib.h>

typedef struct{
    double velocidade;
    Rectangle hitboxveiculo;
    Vector2 posicaoveiculo;

} veiculo;

void inicializaCarro(veiculo* carro);

int colidiu(veiculo carro, Rectangle* mapa, int numero_bordas);

int movimentarCarro1(veiculo* carro1, Rectangle mapa);

int movimentarCarro2(veiculo* carro2, Rectangle mapa);

#endif
