#include "raylib.h"
#include "personagem.h"

Texture2D abrirMapa();

bool checarLimitesDaCamera();

void ColisaoLimitesPista(Rectangle barreiras[], Texture2D mapa);

void LocalizaNitros(Rectangle nitros[], Texture2D mapa);

void LocalizaJumper(Rectangle jumper[], Texture2D mapa);

