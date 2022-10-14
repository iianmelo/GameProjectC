#include "mapa.h"
#include "raylib.h"
#include "personagem.h"

Texture2D abrirmapa(){
    Image mapaPng = LoadImage("assets/images/mapa.png");
    Texture2D mapa_imagem = LoadTextureFromImage(mapaPng);
    UnloadImage(mapaPng);
    return mapa_imagem;
}


void ColisaoLimitesPista(Rectangle barreiras[], Texture2D mapa_imagem){

    //Retangulos do limite da pista

    barreiras[0].x = 0;
    barreiras[0].y = 0;
    barreiras[0].width = 1920 ;
    barreiras[0].height = 60;

    barreiras[1].x = 0;
    barreiras[1].y = 60 ;
    barreiras[1].width = 51;
    barreiras[1].height = 1033;

    barreiras[2].x = 231;
    barreiras[2].y = 231;
    barreiras[2].width = 303;
    barreiras[2].height = 660;

    barreiras[3].x = 539;
    barreiras[3].y = 587;
    barreiras[3].width = 569;
    barreiras[3].height = 309;

    barreiras[4].x = 701 ;
    barreiras[4].y = 61;
    barreiras[4].width = 199;
    barreiras[4].height = 369;

    barreiras[5].x = 1075;
    barreiras[5].y = 243;
    barreiras[5].width = 517;
    barreiras[5].height = 175;

    barreiras[6].x = 1763;
    barreiras[6].y = 61;
    barreiras[6].width = 153;
    barreiras[6].height = 1021;

    barreiras[7].x = 1293;
    barreiras[7].y = 597;
    barreiras[7].width = 465;
    barreiras[7].height = 481;

    barreiras[8].x = 1073;
    barreiras[8].y = 415;
    barreiras[8].width = 45;
    barreiras[8].height = 169;

    barreiras[9].x = 55;
    barreiras[9].y = 1061;
    barreiras[9].width = 1229;
    barreiras[9].height = 17;

    barreiras[10].x = 1073;
    barreiras[10].y = 435;
    barreiras[10].width = 45;
    barreiras[10].height = 169;

    //obstaculos (pedras e barrils)

    barreiras[11].x = 551;
    barreiras[11].y = 297;
    barreiras[11].width = 65;
    barreiras[11].height = 62;

    barreiras[12].x = 314;
    barreiras[12].y = 68;
    barreiras[12].width = 131;
    barreiras[12].height = 50;

    barreiras[13].x = 70;
    barreiras[13].y = 516;
    barreiras[13].width = 65;
    barreiras[13].height = 43;

    barreiras[14].x = 385;
    barreiras[14].y = 908;
    barreiras[14].width = 124;
    barreiras[14].height = 51;

    barreiras[15].x = 999;
    barreiras[15].y = 905;
    barreiras[15].width = 66;
    barreiras[15].height = 64;

    barreiras[16].x = 1213;
    barreiras[16].y = 689;
    barreiras[16].width = 62;
    barreiras[16].height = 46;

    barreiras[17].x = 1113;
    barreiras[17].y = 86;
    barreiras[17].width = 83;
    barreiras[17].height = 49;
    
    //barreira que impede o carro de ir pelo sentido contrario
    barreiras[18].x = 1607;
    barreiras[18].y = 198;
    barreiras[18].width = 138;
    barreiras[18].height = 57;

}
    //nitros (moedas)
void LocalizaNitros(Rectangle nitros[], Texture2D mapa){

    nitros[0].x = 1002;
    nitros[0].y = 104;
    nitros[0].width = 43;
    nitros[0].height = 47;

    nitros[1].x = 944;
    nitros[1].y = 503;
    nitros[1].width = 47;
    nitros[1].height = 42;

    nitros[2].x = 68;
    nitros[2].y = 326;
    nitros[2].width = 51;
    nitros[2].height = 46;

    nitros[3].x = 150;
    nitros[3].y = 803;
    nitros[3].width = 43;
    nitros[3].height = 47;

    nitros[4].x = 767;
    nitros[4].y = 991;
    nitros[4].width = 44;
    nitros[4].height = 44;
}

    //jumper que aumenta a velocidade
void LocalizaJumper(Rectangle jumper[], Texture2D mapa){

    jumper[0].x = 767;
    jumper[0].y = 436;
    jumper[0].width = 92;
    jumper[0].height = 60;

    jumper[1].x = 571;
    jumper[1].y = 908;
    jumper[1].width = 89;
    jumper[1].height = 57;

    jumper[2].x = 339;
    jumper[2].y = 154;
    jumper[2].width = 94;
    jumper[2].height = 58;
}
 
    //linha de partida
    Rectangle linhaDePartida = {1471, 75, 43, 151};

    //linha de chegada
    Rectangle linhaDeChegada = {1604, 291, 152, 49};
