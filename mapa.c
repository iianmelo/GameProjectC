#include "raylib.h"
#include "personagem.h"

Texture2D abrirmapa(){
    Image mapaPng = LoadImage("assets/images/mapa.png");
    Texture2D mapa_imagem = LoadTextureFromImage(mapaPng);
    UnloadImage(mapaPng);
    return mapa_imagem;
}


void ColisaoLimitesPista(Rectangle mapa[], Texture2D mapa_imagem){

    //Retangulos do limite da pista

    mapa[0].x = 0;
    mapa[0].y = 0;
    mapa[0].width = 1920 ;
    mapa[0].height = 60;

    mapa[1].x = 0;
    mapa[1].y = 60 ;
    mapa[1].width = 51;
    mapa[1].height = 1033;

    mapa[2].x = 231;
    mapa[2].y = 231;
    mapa[2].width = 303;
    mapa[2].height = 660;

    mapa[3].x = 539;
    mapa[3].y = 587;
    mapa[3].width = 569;
    mapa[3].height = 309;

    mapa[4].x = 701 ;
    mapa[4].y = 61;
    mapa[4].width = 199;
    mapa[4].height = 369;

    mapa[5].x = 1075;
    mapa[5].y = 243;
    mapa[5].width = 517;
    mapa[5].height = 175;

    mapa[6].x = 1763;
    mapa[6].y = 61;
    mapa[6].width = 153;
    mapa[6].height = 1021;

    mapa[7].x = 1293;
    mapa[7].y = 597;
    mapa[7].width = 465;
    mapa[7].height = 481;

    mapa[8].x = 1073;
    mapa[8].y = 415;
    mapa[8].width = 45;
    mapa[8].height = 169;

    mapa[9].x = 55;
    mapa[9].y = 1061;
    mapa[9].width = 1229;
    mapa[9].height = 17;

    mapa[10].x = 1073;
    mapa[10].y = 435;
    mapa[10].width = 45;
    mapa[10].height = 169;

    //obstaculos (pedras e barrils)

    mapa[11].x = 593;
    mapa[11].y = 469;
    mapa[11].width = 57;
    mapa[11].height = 60;

    mapa[12].x = 314;
    mapa[12].y = 68;
    mapa[12].width = 131;
    mapa[12].height = 51;

    mapa[13].x = 70;
    mapa[13].y = 516;
    mapa[13].width = 65;
    mapa[13].height = 43;

    mapa[14].x = 385;
    mapa[14].y = 908;
    mapa[14].width = 124;
    mapa[14].height = 51;

    mapa[15].x = 999;
    mapa[15].y = 905;
    mapa[15].width = 66;
    mapa[15].height = 64;

    mapa[16].x = 1213;
    mapa[16].y = 689;
    mapa[16].width = 62;
    mapa[16].height = 46;

    mapa[17].x = 1113;
    mapa[17].y = 86;
    mapa[17].width = 83;
    mapa[17].height = 49;

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

    jumper[2].x = 1113;
    jumper[2].y = 86;
    jumper[2].width = 83;
    jumper[2].height = 49;
}
 
    //linha de partida
    Rectangle linhaDePartida;
    linhaDePartida.x = 1471;
    linhaDePartida.y = 75;
    linhaDePartida.width = 43;
    linhaDePartida.height = 151;

    //linha de chegada

    Rectangle linhaDePartida;
    linhaDeChegada.x = 1604;
    linhaDeChegada.y = 291;
    linhaDeChegada.width = 152;
    linhaDeChegada.height = 49; 


