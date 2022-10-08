#include "raylib.h"
#include "animacao.h"


void animarCarro(spritesheetcarro* carro_sheet, Texture2D textura_carro, Texture2D textura_nitro, veiculo carro){

    Vector2 centralizar = {carro.posicaoveiculo.x, carro.posicaoveiculo.y};

    //animar carro caso ele esteja na vertical ou na horizontal: 
    if((*carro_sheet).direcao == 1 || (*carro_sheet).direcao == 2 || (*carro_sheet).direcao == 3 || (*carro_sheet).direcao == 4){
        DrawTexture(textura_carro, carro.hitboxveiculo.x, carro.hitboxveiculo.y, RAYWHITE);
    }

    //animar carro caso ele esteja na diagonal (parametros mais complexos):
    else if((*carro_sheet).direcao == 5){
        DrawTextureEx(textura_carro, centralizar, 45.0f , 1.0f, RAYWHITE);
    }

    else if((*carro_sheet).direcao == 8){
        DrawTextureEx(textura_carro, centralizar, 315.0f , 1.0f, RAYWHITE);
    }

    else if((*carro_sheet).direcao == 7){
        DrawTextureEx(textura_carro, centralizar, 45.0f , 1.0f, RAYWHITE);
    }

    else if((*carro_sheet).direcao == 6){
        DrawTextureEx(textura_carro, centralizar, 315.0f , 1.0f, RAYWHITE);
    }

    //animar carro com o nitro ligado: 
    if((*carro_sheet).nitro == 1){



    }
}
