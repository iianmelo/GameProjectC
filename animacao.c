#include "raylib.h"
#include "animacao.h"


void animarCarro(spritesheetcarro* carro_sheet, Texture2D textura_carro, Texture2D textura_nitro, veiculo carro){

    Vector2 centro_carro = {carro.posicaoveiculo.x, carro.posicaoveiculo.y};
    Rectangle nitro_source = {0, 0, 12, 30};

    //animar carro caso ele esteja na vertical ou na horizontal: 
    if((*carro_sheet).direcao == 1 || (*carro_sheet).direcao == 2 || (*carro_sheet).direcao == 3 || (*carro_sheet).direcao == 4){

        DrawTexture(textura_carro, carro.hitboxveiculo.x, carro.hitboxveiculo.y, RAYWHITE);

        //nitro ligado:
        if((*carro_sheet).nitro == 1){

            switch((*carro_sheet).direcao){
                case 1:
                    Vector2 centro_nitro1 = {centro_carro.x - 19, carro.posicaoveiculo.y + 65};
                    Vector2 centro_nitro2 = {carro.posicaoveiculo.x + 19, carro.posicaoveiculo.y + 65};
                    DrawTextureEx(textura_nitro, centro_nitro1, 0.0f, 1.0f, RAYWHITE);
                    DrawTextureEx(textura_nitro, centro_nitro2, 0.0f, 1.0f, RAYWHITE);
                    break;
                case 2:
                    Vector2 centro_nitro1 = {carro.posicaoveiculo.x - 65, carro.posicaoveiculo.y + 19};
                    Vector2 centro_nitro2 = {carro.posicaoveiculo.x - 65, carro.posicaoveiculo.y - 19};
                    DrawTextureEx(textura_nitro, centro_nitro1, 90.0f, 1.0f, RAYWHITE);
                    DrawTextureEx(textura_nitro, centro_nitro2, 90.0f, 1.0f, RAYWHITE);
                    break;
                case 3:
                    Vector2 centro_nitro1 = {carro.posicaoveiculo.x - 19, carro.posicaoveiculo.y - 65};
                    Vector2 centro_nitro2 = {carro.posicaoveiculo.x + 19, carro.posicaoveiculo.y - 65};
                    DrawTextureEx(textura_nitro, centro_nitro1, 180.0f, 1.0f, RAYWHITE);
                    DrawTextureEx(textura_nitro, centro_nitro2, 180.0f, 1.0f, RAYWHITE);
                    break;
                case 4:
                    Vector2 centro_nitro1 = {carro.posicaoveiculo.x + 65, carro.posicaoveiculo.y + 19};
                    Vector2 centro_nitro2 = {carro.posicaoveiculo.x + 65, carro.posicaoveiculo.y - 19};
                    DrawTextureEx(textura_nitro, centro_nitro1, 270.0f, 1.0f, RAYWHITE);
                    DrawTextureEx(textura_nitro, centro_nitro2, 270.0f, 1.0f, RAYWHITE);
                    break;
            }
        }
    }

    //animar carro caso ele esteja na diagonal (parametros mais complexos):
    else if((*carro_sheet).direcao == 5){
        DrawTextureEx(textura_carro, centro_carro, 45.0f , 1.0f, RAYWHITE);
        
        //nitro ligado:
        if((*carro_sheet).nitro == 1){
            Rectangle nitro1_destination = {carro.posicaoveiculo.x - 25, carro.posicaoveiculo.y + 50, 12, 30};
            Rectangle nitro2_destination = {carro.posicaoveiculo.x + 25, carro.posicaoveiculo.y + 50, 12, 30};
            DrawTexturePro(textura_nitro, nitro_source, nitro1_destination, centro_carro, 45.0f, RAYWHITE);
            DrawTexturePro(textura_nitro, nitro_source, nitro2_destination, centro_carro, 45.0f, RAYWHITE);
        }
    }

    else if((*carro_sheet).direcao == 8){
        DrawTextureEx(textura_carro, centro_carro, 315.0f , 1.0f, RAYWHITE);

        //nitro ligado:
        if((*carro_sheet).nitro == 1){
            Rectangle nitro1_destination = {carro.posicaoveiculo.x - 25, carro.posicaoveiculo.y + 50, 12, 30};
            Rectangle nitro2_destination = {carro.posicaoveiculo.x + 25, carro.posicaoveiculo.y + 50, 12, 30};
            DrawTexturePro(textura_nitro, nitro_source, nitro1_destination, centro_carro, 315.0f, RAYWHITE);
            DrawTexturePro(textura_nitro, nitro_source, nitro2_destination, centro_carro, 315.0f, RAYWHITE);
        }
    }

    else if((*carro_sheet).direcao == 7){
        DrawTextureEx(textura_carro, centro_carro, 45.0f , 1.0f, RAYWHITE);

        //nitro ligado:
        if((*carro_sheet).nitro == 1){
            Rectangle nitro1_destination = {carro.posicaoveiculo.x - 25, carro.posicaoveiculo.y + 50, 12, 30};
            Rectangle nitro2_destination = {carro.posicaoveiculo.x + 25, carro.posicaoveiculo.y + 50, 12, 30};
            DrawTexturePro(textura_nitro, nitro_source, nitro1_destination, centro_carro, 225.0f, RAYWHITE);
            DrawTexturePro(textura_nitro, nitro_source, nitro2_destination, centro_carro, 225.0f, RAYWHITE);
        }
    }

    else if((*carro_sheet).direcao == 6){
        DrawTextureEx(textura_carro, centro_carro, 315.0f , 1.0f, RAYWHITE);

        //nitro ligado:
        if((*carro_sheet).nitro == 1){
            Rectangle nitro1_destination = {carro.posicaoveiculo.x - 25, carro.posicaoveiculo.y + 50, 12, 30};
            Rectangle nitro2_destination = {carro.posicaoveiculo.x + 25, carro.posicaoveiculo.y + 50, 12, 30};
            DrawTexturePro(textura_nitro, nitro_source, nitro1_destination, centro_carro, 135.0f , RAYWHITE);
            DrawTexturePro(textura_nitro, nitro_source, nitro2_destination, centro_carro, 135.0f, RAYWHITE);
        }
    }

}
