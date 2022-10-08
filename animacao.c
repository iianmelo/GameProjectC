#include "raylib.h"
#include "animacao.h"

void animarCarro(spritesheet* carro_sheet, Texture2D* textura_carro, Texture2D* textura_nitro, veiculo carro){

    //animar carro caso ele esteja na vertical ou na horizontal: 
    if(carro_sheet.direcao == 1 || carro_sheet.direcao == 2 || carro_sheet.direcao == 3 || carro_sheet.direcao == 4){
    DrawTexture(textura_carro, carro.hitboxveiculo.x, carro.hitboxveiculo.y, RAYWHITE);
    }

    //animar carro caso ele esteja na diagonal (parametros mais complexos):
    else{

    }

    //animar carro com o nitro ligado: 
    if(carro.nitro == 1){



    }
}
