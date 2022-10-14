#ifndef personagem
#define personagem

#include "raylib.h"
#include "personagem.c"
#include "animacao.h"
#include <math.h>
#include <stdlib.h>

void inicializaCarro(veiculo* carro, int n_carro);

int colidiu(veiculo carro, Rectangle* mapa, int numero_bordas, int direcao);

int movimentarCarro1(veiculo* carro1, Rectangle* barreiras);

int movimentarCarro2(veiculo* carro2, Rectangle* barreiras);

int pegouNitro(veiculo carro, Rectangle* jumpers, int numero_nitros, int direcao);

int pegouMoeda(veiculo carro, Rectangle* nitros, int numero_moedas, int direcao);

#endif
