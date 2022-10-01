#include <stdio.h>
#include <raylib.h>
#include "menu.h"

int flagMenu = 0;

Texture2D imagemMenu;
Texture2D imagemComoJogar;
Texture2D imagemIniciando;
int aux=1;
imagemMenu = LoadTexture("menu_inicial.png");
imagemComoJogar = LoadTexture("como_jogar.png");
imagemIniciando = LoadTexture("iniciandonovo.png");

void paraOndeIr(int aux);
    if(aux==1) {
        iniciarMenu();
    }else if(aux==2){
        iniciandoJogo();
    }else if(aux==3){
        abrirExplicacao();
    }

void iniciarMenu(){
imagemMenu = LoadTexture("menu_inicial.png");
DrawTexture(imagemMenu,0,0, RAYWHITE); //isso aqui é pra desenhar no centro da tela

//agora o que vai acontecer quando pressionar cada tecla
if(IsKeyDown(KEY_S)){
    aux=2;
    paraOndeIr(aux);
}
if(IsKeyDown(KEY_H)){
    aux=3;
    paraOndeIr(aux);
    }
}
void abrirExplicacao(){
    imagemComoJogar = LoadTexture("como_jogar.png");
    DrawTexture(imagemComoJogar,0,0, RAYWHITE);
    if(IsKeyDown(KEY_M)){
      aux=1;
      paraOndeIr(aux);
    }
}

void iniciandoJogo(){
    //desenhar o que vai aparecer agora
    DrawTexture(imagemIniciando,0,0, RAYWHITE);

    //agora para o jogo comecar
    if(IsKeyDown(KEY_BACKSPACE)){
        //colocar a função que inicia o jogo ( pista ja com os carrinhos para o usuario jogar)
    }

    if(IsKeyDown(KEY_M)){
      aux=1;
      paraOndeIr(aux);
    }
}
void fechamento(){
    UnloadTexture(imagemMenu);
    UnloadTexture(imagemIniciando);
    UnloadTexture(imagemComoJogar);
}

