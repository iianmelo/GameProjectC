# include  <stdio.h>
# include  <raylib.h>
# include "menu.h"
# include  "fimDoJogo.h"

void mostrarTelaFinal1 (){
    imagemVencedor1 = LoadTexture ( "vencedor1.png" );
    DrawTexture (imagemVencedor1, 0 , 0 , RAYWHITE);

    // opções que existem nessa tela
    if ( IsKeyDown (KEY_S)){
    aux = 7 ; // cria uma função para sair do jogo
    }
    if ( IsKeyDown (KEY_H)){
    aux = 3 ;
    }
    if ( IsKeyDown (KEY_M)){
    aux = 1;
    }
}
void mostrarTelaFinal2 (){
    imagemVencedor2 = LoadTexture ( "vencedor2.png" );
    DrawTexture (imagemVencedor2, 0 , 0 , RAYWHITE);

    // opções que existem nessa tela
    if ( IsKeyDown (KEY_S)){
    aux= 7 ; // cria uma função para sair do jogo
    }
    if ( IsKeyDown (KEY_H)){
    aux= 3 ;
    }
    if ( IsKeyDown (KEY_M)){
    aux = 1;
    }
}
