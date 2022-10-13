#ifndef animacao
#define animacao

#include "raylib.h"
#include "animacao.c"
#include <stdbool.h>

void startTimer(timer* timer, float tempo_ligado);

void updateTimer(timer* timer);

bool timerDone(timer* timer);

void animarCarro(spritesheetcarro* carro_sheet, Texture2D textura_carro, Texture2D textura_nitro, veiculo carro);

#endif
