#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "personagem.h"
#include "animacao.h"
#include "raylib.h"
#include "menu.h"
#include "mapa.h"
#include "fimDoJogo.h"

float tempo_nitro_ligado = 2.0; 
float velocidade_com_nitro = 5;
float velocidade_sem_nitro = 2;
int numero_nitros = 5; //moedas
int numero_jumpers = 3;
int acaoCarro1 = 0, Carro1nitro, Carro1moeda = 0;
int acaoCarro2 = 0, Carro2nitro, Carro2moeda = 0;
int final = 0;

int main(){

    InitWindow(GetScreenWidth(), GetScreenHeight(), "IP Racers");
    ToggleFullscreen();
    //inicializando e colocando as musicas
    InitAudioDevice();
    Music MusicaMenu= LoadMusicStream("musicaMenu.mp3"); 
    Music MusicaFundo= LoadMusicStream("musicaCircuito.mp3"); 
    Music MusicaNitro = LoadMusicStream("audionitro.mp3");
    Music MusicaBatida = LoadMusicStream("audiobatida.mp3");
    Music MusicaMoeda = LoadMusicStream("audiomoeda.mp3");
    Music MusicaVencedor1 = LoadMusicStream("vencedor1.mp3");
    Music MusicaVencedor2 = LoadMusicStream("vencedor2.mp3");
    
    SetTargetFPS(60);
    //parte  fundamental pra pausar a musica do menu
    bool pause = false;
    
    aux=1;
    
    timer timercarro1 = {0, 0};
    timer timercarro2 = {0, 0};
    spritesheetcarro carro1_sheet = {0, 0.0f, 4}; //nitro comeca desligado e o carro1 nasce apontando para esquerda
    spritesheetcarro carro2_sheet = {0, 0.0f, 4}; //nitro comeca desligado e o carro2 nasce apontando para esquerda

    //retangulos do mapa:
    Rectangle barreiras[18];
    Rectangle nitros[numero_nitros];
    Rectangle jumpers[numero_jumpers];

    //Imagens e Texturas carro 1 (vermelho):
    Image carro1_cima = LoadImage("Car_1_01_cima.png");
    ImageResize (&carro1_cima, 50, 100);
    Texture2D text_carro1_cima = LoadTextureFromImage(carro1_cima);
    
    //Imagens e Texturas carro 2 (amarelo):
    Image carro2_cima = LoadImage("Car_3_01_cima.png");
    ImageResize (&carro2_cima, 50, 100);
    Texture2D text_carro2_cima = LoadTextureFromImage(carro2_cima);

    //Imagens e Texturas nitro:
    Image nitro_imagem = LoadImage("Nitro_006.png");
    ImageResize(&nitro_imagem, 12, 30);
    Texture2D nitro = LoadTextureFromImage(nitro_imagem);

    //Imagens e textura mapa:
    Image mapa_corrida = LoadImage("mapa.png");
    Texture2D mapa_pista = LoadTextureFromImage(mapa_corrida);

    //Texturas menu inicial:
    Texture2D imagemMenu = LoadTexture("menu_inicial.png");
    Texture2D imagemComoJogar = LoadTexture("como_jogar.png");
    Texture2D imagemIniciando = LoadTexture("iniciandonovo.png");
    Texture2D imagemVencedor1 = LoadTexture("vencedor1.png");
    Texture2D imagemVencedor2 = LoadTexture("vencedor2.png");

    ColisaoLimitesPista(barreiras, mapa_pista);
    LocalizaJumper(jumpers, mapa_pista);
    LocalizaNitros(nitros, mapa_pista);
    
    //loop principal do jogo
    while (!WindowShouldClose()){
        
        
        
        veiculo carro1;
        veiculo carro2;
        inicializaCarro(&carro1, 1);
        inicializaCarro(&carro2, 2);

        while(IsKeyUp(KEY_ESCAPE)){ //possibilidade de criar um menu de pausa

        if(aux==4){
            //movimentando os carros:
            acaoCarro1 = movimentarCarro1(&carro1, barreiras);
            acaoCarro2 = movimentarCarro2(&carro2, barreiras);

            if(acaoCarro1 != 0)
            carro1_sheet.direcao = acaoCarro1;
            if(acaoCarro2 != 0)
            carro2_sheet.direcao = acaoCarro2;
            
            //verificando se pegaram moeda:
            Carro1moeda += pegouMoeda(carro1, nitros, numero_nitros, carro1_sheet.direcao);
            Carro2moeda += pegouMoeda(carro2, nitros, numero_nitros, carro2_sheet.direcao);

            if(Carro1moeda != 0){ 
                carro1_sheet.moeda = Carro1moeda;                 
                UpdateMusicStream(MusicaMoeda);
                SetMasterVolume(1.0); }
            if(Carro2moeda != 0){
                carro2_sheet.moeda = Carro1moeda;
                UpdateMusicStream(MusicaMoeda);
                SetMasterVolume(1.0); }
            
            //verificando se pegaram nitro:
            Carro1nitro = pegouNitro(carro1, jumpers, numero_jumpers, carro1_sheet.direcao);
            Carro2nitro = pegouNitro(carro2, jumpers, numero_jumpers, carro2_sheet.direcao);

            if(Carro1nitro == 1)carro1_sheet.nitro = 1;
            if(Carro2nitro == 1)carro2_sheet.nitro = 1;

            //caso peguem o nitro, timer comeca e velocidade aumenta
            if(carro1_sheet.nitro == 1 && timercarro1.ligado == 0){ 
                startTimer(&timercarro1, tempo_nitro_ligado);
                carro1.velocidade = velocidade_com_nitro;
                timercarro1.ligado = 1;
                UpdateMusicStream(MusicaNitro);
                SetMasterVolume(1.0); 
            }    
            if(carro2_sheet.nitro == 1 && timercarro2.ligado == 0){
                startTimer(&timercarro2, tempo_nitro_ligado);
                carro2.velocidade = velocidade_com_nitro;
                timercarro2.ligado = 1;
                UpdateMusicStream(MusicaNitro);
                SetMasterVolume(1.0); 
            }
            
            updateTimer(&timercarro1);
            updateTimer(&timercarro2);
            
            //se o nitro acabar velocidade diminui
            if(carro1_sheet.nitro == 1 && timerDone(&timercarro1)){
                carro1.velocidade = velocidade_sem_nitro;
                carro1_sheet.nitro = 0;
                timercarro1.ligado = 0;
            }
            if(carro2_sheet.nitro == 1 && timerDone(&timercarro2)){
                carro2.velocidade = velocidade_sem_nitro;
                carro2_sheet.nitro = 0;
                timercarro2.ligado = 0;
            }
            if(CheckCollisionRecs(carro1.hitboxveiculo, linhaDeChegada)) {
                final = 1;
                aux = 7;
                //audiobatida
                UpdateMusicStream(MusicaBatida);
                SetMasterVolume(1.0);
                //
                inicializaCarro(&carro1, 1);
                inicializaCarro(&carro2, 2);
            }
            else if(CheckCollisionRecs(carro2.hitboxveiculo, linhaDeChegada)) {
                final = 2;
                aux = 7;
                //audiobatida
                UpdateMusicStream(MusicaBatida);
                SetMasterVolume(1.0);
                //
                inicializaCarro(&carro1, 1);
                inicializaCarro(&carro2, 2);
            }
        }
        if(aux==7 && final==1) {
            mostrarTelaFinal1(imagemVencedor1);
            //audiovencedor1
            PauseMusicStream(MusicaFundo);
            UpdateMusicStream(MusicaVencedor1);
            SetMasterVolume(1.0);
        }
        if(aux==7 && final==2) {
            mostrarTelaFinal2(imagemVencedor2);
            //audiovencedor2
            PauseMusicStream(MusicaFundo);
            UpdateMusicStream(MusicaVencedor2);
            SetMasterVolume(1.0);
        }
            BeginDrawing();
            ClearBackground(RAYWHITE);
            if(aux==1) {
                PlayMusicStream(MusicaMenu);
                //parte da musica menu
                UpdateMusicStream(MusicaMenu); 
                SetMasterVolume(0.7);
                final = 0;
                iniciarMenu(imagemMenu);
            }
            else if(aux==2){
                iniciandoJogo(imagemIniciando);
            }
            else if(aux==3){
                final = 0;
                abrirExplicacao(imagemComoJogar);
            }
            else if(aux==4){ 
                //pausa musica menu e toca a do circuito
                PauseMusicStream(MusicaMenu);
                UpdateMusicStream(MusicaFundo); 
                SetMasterVolume(0.7);
                //animando os carros:
                DrawTexture(mapa_pista, 0, 0, RAYWHITE);
                animarCarro(&carro1_sheet, text_carro1_cima, nitro, &carro1);
                animarCarro(&carro2_sheet, text_carro2_cima, nitro, &carro2);
            }
            EndDrawing();
        }
    }

    UnloadImage(mapa_corrida);
    UnloadImage(carro1_cima);
    UnloadImage(carro2_cima);
    UnloadImage(nitro_imagem);

    UnloadTexture(imagemMenu);
    UnloadTexture(imagemIniciando);
    UnloadTexture(imagemComoJogar);
    UnloadTexture(text_carro1_cima);
    UnloadTexture(text_carro2_cima);
    UnloadTexture(nitro);
    
    //
    UnloadMusicStream(MusicaMenu); 
    UnloadMusicStream(MusicaFundo); 
    UnloadMusicStream(MusicaNitro);
    UnloadMusicStream(MusicaBatida); 
    UnloadMusicStream(MusicaMoeda); 
    UnloadMusicStream(MusicaVencedor1); 
    UnloadMusicStream(MusicaVencedor2); 
    //
    CloseAudioDevice();

    CloseWindow();
    return 0;


    
} 
