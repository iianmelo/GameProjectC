#ifndef mapa
#define mapa

#include "mapa.c"
#include "raylib.h"
#include "personagem.h"

Texture2D abrirMapa();

void ColisaoLimitesPista(Rectangle barreiras[], Texture2D mapa);

void LocalizaNitros(Rectangle nitros[], Texture2D mapa);

void LocalizaJumper(Rectangle jumper[], Texture2D mapa);

#endif
