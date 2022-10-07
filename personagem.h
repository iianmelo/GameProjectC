#include "raylib.h"

typedef struct{
    double velocidade;
    Rectangle hitboxveiculo;
    Vector2 posicaoveiculo;

} veiculo;

#include "jogador.h"
#include <math.h>
#include  <stdlib.h>

void inicializaCarro(veiculo* carro);

int movimentarCarro1(veiculo* carro1, Rectangle mapa);

int movimentarCarro2(veiculo* carro2, Rectangle mapa);
