#include "raylib.h"
#include "animacao.h"
#include <stdio.h>
#include <stdbool.h>

typedef struct{
    float tempo_duracao;
} timer;

typedef struct{
    int nitro; //se o nitro estiver ligado, fazer a animacao do nitro
    float angulo; 
    int direcao; //esse parametro dependera do valor que a funcao de movimentar o carro retornar
} spritesheetcarro;

typedef struct{
    float velocidade;
    Rectangle hitboxveiculo;
    Vector2 posicaoveiculo;
} veiculo;

void startTimer(timer* timer, float tempo_ligado){

    if(timer != NULL){
        timer->tempo_duracao = tempo_ligado;
    }
}

void updateTimer(timer* timer){

    if(timer != NULL && timer->tempo_duracao > 0){
        timer->tempo_duracao -= GetFrameTime();
    }  
}

bool timerDone(timer* timer){
    
    if(timer != NULL){
        return timer->tempo_duracao <= 0;
    }
    return 0;
}

void animarCarro(spritesheetcarro* carro_sheet, Texture2D textura_carro, Texture2D textura_nitro, veiculo* carro){

    Vector2 centro_carro = {25, 50};
    Vector2 centro_nitro1 = {25, -45}; //centro do carro em relacao ao canto superior esquerdo do nitro 1 
    Vector2 centro_nitro2 = {-13, -45}; //centro do carro em relacao ao canto superior esquerdo do nitro 2
    Rectangle source = {0, 0, 50, 100};
    Rectangle source2 = {0, 0, 12, 30};
    Rectangle destination = {carro->posicaoveiculo.x, carro->posicaoveiculo.y, 50, 100};
    Rectangle destination_nitro1 = {carro->posicaoveiculo.x, carro->posicaoveiculo.y, 12, 30};
    Rectangle destination_nitro2 = {carro->posicaoveiculo.x, carro->posicaoveiculo.y, 12, 30};

    //desenhando a hitbox:
    //DrawRectangleRec(carro->hitboxveiculo, BLACK);

    if(carro_sheet->direcao == 1){
        DrawTexturePro(textura_carro, source, destination, centro_carro, 0.0f, RAYWHITE);
        if(carro_sheet->nitro == 1){
            DrawTexturePro(textura_nitro, source2, destination_nitro1, centro_nitro1, 0.0f, RAYWHITE);
            DrawTexturePro(textura_nitro, source2, destination_nitro2, centro_nitro2, 0.0f, RAYWHITE);
        }
    }

    else if(carro_sheet->direcao == 2){
        DrawTexturePro(textura_carro, source, destination, centro_carro, 90.0f, RAYWHITE);
        if(carro_sheet->nitro == 1){
            DrawTexturePro(textura_nitro, source2, destination_nitro1, centro_nitro1, 90.0f, RAYWHITE);
            DrawTexturePro(textura_nitro, source2, destination_nitro2, centro_nitro2, 90.0f, RAYWHITE);
        }
    }

    else if(carro_sheet->direcao == 3){
        DrawTexturePro(textura_carro, source, destination, centro_carro, 180.0f, RAYWHITE);
        if(carro_sheet->nitro == 1){
            DrawTexturePro(textura_nitro, source2, destination_nitro1, centro_nitro1, 180.0f, RAYWHITE);
            DrawTexturePro(textura_nitro, source2, destination_nitro2, centro_nitro2, 180.0f, RAYWHITE);
        }
    }

    else if(carro_sheet->direcao == 4){
        DrawTexturePro(textura_carro, source, destination, centro_carro, 270.0f, RAYWHITE);
        if(carro_sheet->nitro == 1){
            DrawTexturePro(textura_nitro, source2, destination_nitro1, centro_nitro1, 270.0f, RAYWHITE);
            DrawTexturePro(textura_nitro, source2, destination_nitro2, centro_nitro2, 270.0f, RAYWHITE);
        }
    }
    
    else if(carro_sheet->direcao == 5){
        DrawTexturePro(textura_carro, source, destination, centro_carro, 45.0f, RAYWHITE);
        
        //nitro ligado:
        if(carro_sheet->nitro == 1){
            DrawTexturePro(textura_nitro, source2, destination_nitro1, centro_nitro1, 45.0f, RAYWHITE);
            DrawTexturePro(textura_nitro, source2, destination_nitro2, centro_nitro2, 45.0f, RAYWHITE);
        }
    }

    else if(carro_sheet->direcao == 8){
        DrawTexturePro(textura_carro, source, destination, centro_carro, 315.0f, RAYWHITE);

        //nitro ligado:
        if(carro_sheet->nitro == 1){
            DrawTexturePro(textura_nitro, source2, destination_nitro1, centro_nitro1, 315.0f, RAYWHITE);
            DrawTexturePro(textura_nitro, source2, destination_nitro2, centro_nitro2, 315.0f, RAYWHITE);
        }
    }

    else if(carro_sheet->direcao == 7){
        DrawTexturePro(textura_carro, source, destination, centro_carro, 225.0f, RAYWHITE);

        //nitro ligado:
        if(carro_sheet->nitro == 1){
            DrawTexturePro(textura_nitro, source2, destination_nitro1, centro_nitro1, 225.0f, RAYWHITE);
            DrawTexturePro(textura_nitro, source2, destination_nitro2, centro_nitro2, 225.0f, RAYWHITE);
        }
    }

    else if(carro_sheet->direcao == 6){
        DrawTexturePro(textura_carro, source, destination, centro_carro, 135.0f, RAYWHITE);

        //nitro ligado:
        if(carro_sheet->nitro == 1){
            DrawTexturePro(textura_nitro, source2, destination_nitro1, centro_nitro1, 135.0f, RAYWHITE);
            DrawTexturePro(textura_nitro, source2, destination_nitro2, centro_nitro2, 135.0f, RAYWHITE);
        }
    }
    DrawCircle(carro->posicaoveiculo.x, carro->posicaoveiculo.y, 6, GREEN);
}
