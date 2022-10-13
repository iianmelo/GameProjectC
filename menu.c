#include <stdio.h>
#include "raylib.h"
#include "menu.h"

int aux;

void iniciarMenu(Texture2D imagemMenu){
    imagemMenu = LoadTexture("menu_inicial.png");
    DrawTexture(imagemMenu,0,0, RAYWHITE); //isso aqui é pra desenhar no centro da tela

    //agora o que vai acontecer quando pressionar cada tecla
    if(IsKeyDown(KEY_S)){
        aux=2;
    }
    if(IsKeyDown(KEY_H)){
      aux=3;
    }
}

void abrirExplicacao(Texture2D imagemComoJogar){
    imagemComoJogar = LoadTexture("como_jogar.png");
    DrawTexture(imagemComoJogar,0,0, RAYWHITE);
    if(IsKeyDown(KEY_M)){
      aux=1;
    }
}

void iniciandoJogo(Texture2D imagemIniciando){
    //desenhar o que vai aparecer agora
    imagemIniciando = LoadTexture("iniciandonovo.png");
    DrawTexture(imagemIniciando,0,0, RAYWHITE);

    //agora para o jogo comecar
    if(IsKeyDown(KEY_BACKSPACE)){
        aux=4;
        //colocar a função que inicia o jogo ( pista ja com os carrinhos para o usuario jogar)
    }

    if(IsKeyDown(KEY_M)){
      aux=1;
    }
}
