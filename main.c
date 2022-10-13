#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "personagem.h"
#include "animacao.h"
#include "raylib.h"
#include "menu.h"
#include "mapa.h"
#include "fimDoJogo.h"

float tempo_nitro_ligado = 10.0; 
float velocidade_com_nitro = 5;
float velocidade_sem_nitro = 2;
//int numero_bordas = 100; //numero da quantidade de retangulos do mapa
int numero_nitros = 5; //numero da quantidade de retangulos que sao boosts de nitro
int acaoCarro1;
int acaoCarro2;

int main(){

    InitWindow(GetScreenWidth(), GetScreenHeight(), "IP Racers");
    ToggleFullscreen();
    InitAudioDevice();
    SetTargetFPS(60);
    int ScreenWid = GetScreenWidth();
    int ScreenHei = GetScreenHeight();
    aux=1;

    timer timercarro1 = {0};
    timer timercarro2 = {0};
    spritesheetcarro carro1_sheet = {0, 0.0f, 1}; //nitro comeca desligado e o carro1 nasce apontando para cima
    spritesheetcarro carro2_sheet = {0, 0.0f, 1}; //nitro comeca desligado e o carro2 nasce apontando para cima
    Rectangle mapa = {0, 0, ScreenWid, ScreenHei};

    //Imagens e Texturas carro 1 (vermelho):
    Image carro1_cima = LoadImage("Car_1_01_cima.png");
    ImageResize (&carro1_cima, 50, 100);
    Image carro1_direita = LoadImage("Car_1_01_direita.png"); 
    ImageResize(&carro1_direita, 100, 50);
    Image carro1_esquerda = LoadImage("Car_1_01_esquerda.png");
    ImageResize(&carro1_esquerda, 100, 50);
    Image carro1_baixo = LoadImage("Car_1_01_baixo.png");
    ImageResize(&carro1_baixo, 50, 100);

    Texture2D text_carro1_cima = LoadTextureFromImage(carro1_cima);
    Texture2D text_carro1_direita = LoadTextureFromImage(carro1_direita);
    Texture2D text_carro1_esquerda = LoadTextureFromImage(carro1_esquerda);
    Texture2D text_carro1_baixo = LoadTextureFromImage(carro1_baixo);
    Texture2D textura1_atual;
    
    //Imagens e Texturas carro 2 (amarelo):
    Image carro2_cima = LoadImage("Car_3_01_cima.png");
    ImageResize (&carro2_cima, 50, 100);
    Image carro2_direita = LoadImage("Car_3_01_direita.png"); 
    ImageResize(&carro2_direita, 100, 50);
    Image carro2_esquerda = LoadImage("Car_3_01_esquerda.png");
    ImageResize(&carro2_esquerda, 100, 50);
    Image carro2_baixo = LoadImage("Car_3_01_baixo.png");
    ImageResize(&carro2_baixo, 50, 100);

    Texture2D text_carro2_cima = LoadTextureFromImage(carro2_cima);
    Texture2D text_carro2_direita = LoadTextureFromImage(carro2_direita);
    Texture2D text_carro2_esquerda = LoadTextureFromImage(carro2_esquerda);
    Texture2D text_carro2_baixo = LoadTextureFromImage(carro2_baixo);
    Texture2D textura2_atual;

    //Imagens e Texturas nitro:
    Image nitro_imagem = LoadImage("Nitro_006.png");
    ImageResize(&nitro_imagem, 12, 30);
    Texture2D nitro = LoadTextureFromImage(nitro_imagem);

    Image mapa_corrida = LoadImage("mapa.png");
    Texture2D mapa_pista = LoadTextureFromImage(mapa_corrida);

    Texture2D imagemMenu = LoadTexture("menu_inicial.png");
    Texture2D imagemComoJogar = LoadTexture("como_jogar.png");
    Texture2D imagemIniciando = LoadTexture("iniciandonovo.png");

    //loop principal do jogo
    while (!WindowShouldClose()){
        
        veiculo carro1;
        veiculo carro2;
        inicializaCarro(&carro1);
        inicializaCarro(&carro2);

        while(IsKeyUp(KEY_ESCAPE)){ //possibilidade de criar um menu de pausa

            //movimentando os carros:
            acaoCarro1 = movimentarCarro1(&carro1, mapa);
            acaoCarro2 = movimentarCarro2(&carro2, mapa);
            carro1_sheet.direcao = acaoCarro1;
            carro2_sheet.direcao = acaoCarro2;
            
            //verificando se pegaram nitro:
            carro1_sheet.nitro = pegouNitro(&carro1_sheet, &carro1, mapa, numero_bordas, numero_nitros);
            carro2_sheet.nitro = pegouNitro(&carro2_sheet, &carro2, mapa, numero_bordas, numero_nitros);

            //caso peguem o nitro, timer comeca e velocidade aumenta
            if(carro1_sheet.nitro == 1){
                startTimer(&timercarro1, tempo_nitro_ligado);
                carro1.velocidade = velocidade_com_nitro;
            }    
            if(carro2_sheet.nitro == 1){
                startTimer(&timercarro2, tempo_nitro_ligado);
                carro2.velocidade = velocidade_com_nitro;
            }
            
            updateTimer(&timercarro1);
            updateTimer(&timercarro2);
            
            //se o nitro acabar velocidade diminui
            if(carro1_sheet.nitro == 1 && timerDone(&timercarro1)){
                carro1.velocidade = velocidade_sem_nitro;
                carro1_sheet.nitro = 0;
            }
            if(carro2_sheet.nitro == 1 && timerDone(&timercarro2)){
                carro2.velocidade = velocidade_sem_nitro;
                carro2_sheet.nitro = 0;
            }
    
            
            switch(acaoCarro1){

                case 1:
                    textura1_atual = LoadTextureFromImage(carro1_cima);
                    break;
                case 2: 
                    textura1_atual = LoadTextureFromImage(carro1_direita);
                    break;
                case 3:
                    textura1_atual = LoadTextureFromImage(carro1_baixo);
                    break;
                case 4:
                    textura1_atual = LoadTextureFromImage(carro1_esquerda);
                    break;
                case 5:
                    textura1_atual = LoadTextureFromImage(carro1_cima);
                    break;
                case 6:
                    textura1_atual = LoadTextureFromImage(carro1_baixo);
                    break;
                case 7:
                    textura1_atual = LoadTextureFromImage(carro1_baixo);
                    break;
                case 8:
                    textura1_atual = LoadTextureFromImage(carro1_cima);
                    break;
            }

            switch(acaoCarro2){
                
                case 1:
                    textura2_atual = LoadTextureFromImage(carro2_cima);
                    break;
                case 2: 
                    textura2_atual = LoadTextureFromImage(carro2_direita);
                    break;
                case 3:
                    textura2_atual = LoadTextureFromImage(carro2_baixo);
                    break;
                case 4:
                    textura2_atual = LoadTextureFromImage(carro2_esquerda);
                    break; 
                case 5:
                    textura2_atual = LoadTextureFromImage(carro2_cima);
                    break;
                case 6:
                    textura2_atual = LoadTextureFromImage(carro2_baixo);
                    break;
                case 7:
                    textura2_atual = LoadTextureFromImage(carro2_baixo);
                    break;
                case 8:
                    textura2_atual = LoadTextureFromImage(carro2_cima);
                    break;
            }

            BeginDrawing();
            ClearBackground(RAYWHITE);
            if(aux==1) {
                iniciarMenu(imagemMenu);
            }
            else if(aux==2){
                iniciandoJogo(imagemIniciando);
            }
            else if(aux==3){
                abrirExplicacao(imagemComoJogar);
            }
            else if(aux==4){ 
            //animando os carros:
                DrawTexture(mapa_pista, 0, 0, RAYWHITE);
                animarCarro(&carro1_sheet, textura1_atual, nitro, carro1);
                animarCarro(&carro2_sheet, textura2_atual, nitro, carro2);
            }
            if((*carro1).posicaoveiculo.y == 390){
                mostrarTelaFinal1(imagemVencedor1);
            }
            else if((*carro2).posicao.y == 390){
                mostrarTelaFinal2(imagemVencedor2);
            }
            EndDrawing();
        }
    }
    if(aux==7){
        UnloadImage(mapa_corrida);
        UnloadImage(carro1_cima);
        UnloadImage(carro1_direita);
        UnloadImage(carro1_esquerda);
        UnloadImage(carro1_baixo);
        UnloadImage(carro2_cima);
        UnloadImage(carro2_direita);
        UnloadImage(carro2_esquerda);
        UnloadImage(carro2_baixo);
        UnloadImage(nitro_imagem);

        UnloadTexture(imagemMenu);
        UnloadTexture(imagemIniciando);
        UnloadTexture(imagemComoJogar);
        UnloadTexture(text_carro1_cima);
        UnloadTexture(text_carro1_direita);
        UnloadTexture(text_carro1_esquerda);
        UnloadTexture(text_carro1_baixo);
        UnloadTexture(text_carro2_cima);
        UnloadTexture(text_carro2_direita);
        UnloadTexture(text_carro2_esquerda);
        UnloadTexture(text_carro2_baixo);
        UnloadTexture(textura1_atual);
        UnloadTexture(textura2_atual);
        UnloadTexture(nitro);

        CloseAudioDevice();

        CloseWindow();
    }
    return 0;
}
