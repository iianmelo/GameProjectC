#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "personagem.h"
#include "animacao.h"

int numero_bordas = 100; //numero da quantidade de retangulos do mapa
int numero_nitros = 10; //numero da quantidade de retangulos que sao boosts de nitro
int acaoCarro1;
int acaoCarro2;

int main(){

    InitWindow(GetScreenWidth(), GetScreenHeight(), "IPRacers");
    ToggleFullscreen();
    InitAudioDevice();
    SetTargetFPS(60);
    int ScreenWid = GetScreenWidth();
    int ScreenHei = GetScreenHeight();

    spritesheetcarro carro1_sheet = {0, 0.0f, 1}; //nitro comeca desligado e o carro1 nasce apontando para cima
    spritesheetcarro carro2_sheet = {0, 0.0f, 1}; //nitro comeca desligado e o carro2 nasce apontando para cima
    Rectangle mapa = {0, 0, ScreenWid, ScreenHei};

    //Imagens e Texturas carro 1 (vermelho):
    Image carro1_cima = LoadImage("C:/Users/Ianme/Downloads/craftpix-889156-free-racing-game-kit/PNG/Car_1_Main_Positions/Car_1_01_cima.png");
    ImageResize (&carro1_cima, 50, 100);
    Image carro1_direita = LoadImage("C:/Users/Ianme/Downloads/craftpix-889156-free-racing-game-kit/PNG/Car_1_Main_Positions/Car_1_01_direita.png"); 
    ImageResize(&carro1_direita, 100, 50);
    Image carro1_esquerda = LoadImage("C:/Users/Ianme/Downloads/craftpix-889156-free-racing-game-kit/PNG/Car_1_Main_Positions/Car_1_01_esquerda.png");
    ImageResize(&carro1_direita, 100, 50);
    Image carro1_baixo = LoadImage("C:/Users/Ianme/Downloads/craftpix-889156-free-racing-game-kit/PNG/Car_1_Main_Positions/Car_1_01_baixo.png");
    ImageResize(&carro1_baixo, 50, 100);

    Texture2D text_carro1_cima = LoadTextureFromImage(carro1_cima);
    Texture2D text_carro1_direita = LoadTextureFromImage(carro1_direita);
    Texture2D text_carro1_esquerda = LoadTextureFromImage(carro1_esquerda);
    Texture2D text_carro1_baixo = LoadTextureFromImage(carro1_baixo);
    Texture2D textura1_atual;
    
    //Imagens e Texturas carro 2 (amarelo):
    Image carro2_cima = LoadImage("C:/Users/Ianme/Downloads/craftpix-889156-free-racing-game-kit/PNG/Car_1_Main_Positions/Car_3_01_cima.png");
    ImageResize (&carro2_cima, 50, 100);
    Image carro2_direita = LoadImage("C:/Users/Ianme/Downloads/craftpix-889156-free-racing-game-kit/PNG/Car_1_Main_Positions/Car_3_01_direita.png"); 
    ImageResize(&carro2_direita, 100, 50);
    Image carro2_esquerda = LoadImage("C:/Users/Ianme/Downloads/craftpix-889156-free-racing-game-kit/PNG/Car_1_Main_Positions/Car_3_01_esquerda.png");
    ImageResize(&carro2_direita, 100, 50);
    Image carro2_baixo = LoadImage("C:/Users/Ianme/Downloads/craftpix-889156-free-racing-game-kit/PNG/Car_1_Main_Positions/Car_3_01_baixo.png");
    ImageResize(&carro2_baixo, 50, 100);

    Texture2D text_carro2_cima = LoadTextureFromImage(carro2_cima);
    Texture2D text_carro2_direita = LoadTextureFromImage(carro2_direita);
    Texture2D text_carro2_esquerda = LoadTextureFromImage(carro2_esquerda);
    Texture2D text_carro2_baixo = LoadTextureFromImage(carro2_baixo);
    Texture2D textura2_atual;

    //Imagens e Texturas nitro:
    Image nitro_imagem = LoadImage("C:/Users/Ianme/Downloads/craftpix-889156-free-racing-game-kit/PNG/Car_Effects/Nitro/Nitro_006.png");
    ImageResize(&nitro_imagem, 12, 30);
    Texture2D nitro = LoadTextureFromImage(nitro_imagem);

    //loop principal do jogo
    while (!WindowShouldClose()){
        
        veiculo carro1;
        veiculo carro2;
        inicializaCarro(&carro1);
        inicializaCarro(&carro2);

        while(IsKeyUp(KEY_ESCAPE)){ //possibilidade de criar um menu de pausa

            BeginDrawing();

            ClearBackground(RAYWHITE);
            
            //movimentando os carros:
            acaoCarro1 = movimentarCarro1(&carro1, mapa);
            acaoCarro2 = movimentarCarro2(&carro2, mapa);
            carro1_sheet.direcao = acaoCarro1;
            carro2_sheet.direcao = acaoCarro2;
            //verificando se pegaram nitro:
            carro1_sheet.nitro = pegouNitro(&carro1_sheet, &carro1, mapa, numero_bordas, numero_nitros);
            carro1_sheet.nitro = pegouNitro(&carro2_sheet, &carro2, mapa, numero_bordas, numero_nitros);    

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
                    textura2_atual = LoadTextureFromImage(carro2_cima);
                    break;
                case 3:
                    textura2_atual = LoadTextureFromImage(carro2_cima);
                    break;
                case 4:
                    textura2_atual = LoadTextureFromImage(carro2_cima);
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
            
            //animando os carros:
            animarCarro(&carro1_sheet, textura1_atual, nitro, carro1);
            animarCarro(&carro2_sheet, textura2_atual, nitro, carro2);

            EndDrawing();
        }
    }


    UnloadImage(carro1_cima);
    UnloadImage(carro1_direita);
    UnloadImage(carro1_esquerda);
    UnloadImage(carro1_baixo);
    UnloadImage(carro2_cima);
    UnloadImage(carro2_direita);
    UnloadImage(carro2_esquerda);
    UnloadImage(carro2_baixo);
    UnloadImage(nitro_imagem);

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
    return 0;
}
