#include "raylib.h"
#include "personagem.h"
#include "animacao.h"
#include <stdbool.h>
#include <math.h>

int numero_bordas = 18;

void inicializaCarro(veiculo* carro, int n_carro){
    
    carro->velocidade = 2; //velocidade que se alterará caso o nitro esteja ativo

    if(n_carro==1){
    carro->posicaoveiculo.x = 1575; //posicao na qual o carro 1 inicializado comecara (centro do carro)
    carro->posicaoveiculo.y = 110;
    }
    else if(n_carro==2){
    carro->posicaoveiculo.x = 1575; //posicao na qual o carro 2 inicializado comecara (centro do carro)
    carro->posicaoveiculo.y = 190;
    }

    //hitbox (com o carro na horizontal):
    carro->hitboxveiculo.x = carro->posicaoveiculo.x - 50;
    carro->hitboxveiculo.y = carro->posicaoveiculo.y - 25;
    carro->hitboxveiculo.width = 100;
    carro->hitboxveiculo.height = 50;

    return;

}

int colidiu(veiculo carro, Rectangle* barreiras, int numero_bordas, int direcao){

    int colidiu = 0;

    if(direcao == 1 || direcao == 2 || direcao == 3 || direcao == 4){
    for(int i=0 ; i<numero_bordas ; i++){
        if(CheckCollisionRecs(carro.hitboxveiculo, barreiras[i])){
            colidiu = 1;
        }
    }
    }

    else if(direcao == 5 || direcao == 7){
        float rotacao = 45.0f;

        Vector2 A = {carro.posicaoveiculo.x + ((25) * cos(rotacao) - (-50) * sin(rotacao)) , carro.posicaoveiculo.y + ((25) * sin(rotacao) + (-50) * cos(rotacao))};
        Vector2 B = {carro.posicaoveiculo.x + ((-25) * cos(rotacao) - (-50) * sin(rotacao)) , carro.posicaoveiculo.y + ((-25) * sin(rotacao) + (-50) * cos(rotacao))};
        Vector2 C = {carro.posicaoveiculo.x + ((-25) * cos(rotacao) - (50) * sin(rotacao)), carro.posicaoveiculo.y + ((-25) * sin(rotacao) + (50) * cos(rotacao))};
        Vector2 D = {carro.posicaoveiculo.x + ((25) * cos(rotacao) - (50) * sin(rotacao)) , carro.posicaoveiculo.y + ((25) * sin(rotacao) + (50) * cos(rotacao))};
        Vector2 AD = {carro.posicaoveiculo.x + ((25) * cos(rotacao) - (0) * sin(rotacao)) , carro.posicaoveiculo.y + ((25) * sin(rotacao) + (0) * cos(rotacao))};
        Vector2 CD = {carro.posicaoveiculo.x + ((0) * cos(rotacao) - (50) * sin(rotacao)) , carro.posicaoveiculo.y + ((0) * sin(rotacao) + (50) * cos(rotacao))};
        Vector2 BC = {carro.posicaoveiculo.x + ((-25) * cos(rotacao) - (0) * sin(rotacao)) , carro.posicaoveiculo.y + ((-25) * sin(rotacao) + (0) * cos(rotacao))};
        Vector2 AB = {carro.posicaoveiculo.x + ((0) * cos(rotacao) - (-50) * sin(rotacao)) , carro.posicaoveiculo.y + ((0) * sin(rotacao) + (-50) * cos(rotacao))};

        for(int i=0 ; i<numero_bordas ; i++){
            if(CheckCollisionPointRec(A, barreiras[i])) colidiu = 1;
            if(CheckCollisionPointRec(B, barreiras[i])) colidiu = 1;
            if(CheckCollisionPointRec(C, barreiras[i])) colidiu = 1;
            if(CheckCollisionPointRec(D, barreiras[i])) colidiu = 1;
            if(CheckCollisionPointRec(AD, barreiras[i])) colidiu = 1;
            if(CheckCollisionPointRec(CD, barreiras[i])) colidiu = 1;
            if(CheckCollisionPointRec(BC, barreiras[i])) colidiu = 1;
            if(CheckCollisionPointRec(AB, barreiras[i])) colidiu = 1;
        }

    }

    else  if(direcao == 8 || direcao == 6){

        float rotacao = 135.0f;

        Vector2 A = {carro.posicaoveiculo.x + ((25) * cos(rotacao) - (-50) * sin(rotacao)) , carro.posicaoveiculo.y + ((25) * sin(rotacao) + (-50) * cos(rotacao))};
        Vector2 B = {carro.posicaoveiculo.x + ((-25) * cos(rotacao) - (-50) * sin(rotacao)) , carro.posicaoveiculo.y + ((-25) * sin(rotacao) + (-50) * cos(rotacao))};
        Vector2 C = {carro.posicaoveiculo.x + ((-25) * cos(rotacao) - (50) * sin(rotacao)), carro.posicaoveiculo.y + ((-25) * sin(rotacao) + (50) * cos(rotacao))};
        Vector2 D = {carro.posicaoveiculo.x + ((25) * cos(rotacao) - (50) * sin(rotacao)) , carro.posicaoveiculo.y + ((25) * sin(rotacao) + (50) * cos(rotacao))};
        Vector2 AD = {carro.posicaoveiculo.x + ((25) * cos(rotacao) - (0) * sin(rotacao)) , carro.posicaoveiculo.y + ((25) * sin(rotacao) + (0) * cos(rotacao))};
        Vector2 CD = {carro.posicaoveiculo.x + ((0) * cos(rotacao) - (50) * sin(rotacao)) , carro.posicaoveiculo.y + ((0) * sin(rotacao) + (50) * cos(rotacao))};
        Vector2 BC = {carro.posicaoveiculo.x + ((-25) * cos(rotacao) - (0) * sin(rotacao)) , carro.posicaoveiculo.y + ((-25) * sin(rotacao) + (0) * cos(rotacao))};
        Vector2 AB = {carro.posicaoveiculo.x + ((0) * cos(rotacao) - (-50) * sin(rotacao)) , carro.posicaoveiculo.y + ((0) * sin(rotacao) + (-50) * cos(rotacao))};

        for(int i=0 ; i<numero_bordas ; i++){
            if(CheckCollisionPointRec(A, barreiras[i])) colidiu = 1;
            if(CheckCollisionPointRec(B, barreiras[i])) colidiu = 1;
            if(CheckCollisionPointRec(C, barreiras[i])) colidiu = 1;
            if(CheckCollisionPointRec(D, barreiras[i])) colidiu = 1;
            if(CheckCollisionPointRec(AD, barreiras[i])) colidiu = 1;
            if(CheckCollisionPointRec(CD, barreiras[i])) colidiu = 1;
            if(CheckCollisionPointRec(BC, barreiras[i])) colidiu = 1;
            if(CheckCollisionPointRec(AB, barreiras[i])) colidiu = 1;
        }
    }

    return colidiu;
}

int pegouNitro(veiculo carro, Rectangle* jumpers, int numero_nitros, int direcao){
   
   int pegou = 0;

    if(direcao == 1 || direcao == 2 || direcao == 3 || direcao == 4){
    for(int i=0 ; i<numero_nitros ; i++){
        if(CheckCollisionRecs(carro.hitboxveiculo, jumpers[i])){
            pegou = 1;
        }
    }
    }

    else if(direcao == 5 || direcao == 7){
        float rotacao = 45.0f;

        Vector2 A = {carro.posicaoveiculo.x + ((25) * cos(rotacao) - (-50) * sin(rotacao)) , carro.posicaoveiculo.y + ((25) * sin(rotacao) + (-50) * cos(rotacao))};
        Vector2 B = {carro.posicaoveiculo.x + ((-25) * cos(rotacao) - (-50) * sin(rotacao)) , carro.posicaoveiculo.y + ((-25) * sin(rotacao) + (-50) * cos(rotacao))};
        Vector2 C = {carro.posicaoveiculo.x + ((-25) * cos(rotacao) - (50) * sin(rotacao)), carro.posicaoveiculo.y + ((-25) * sin(rotacao) + (50) * cos(rotacao))};
        Vector2 D = {carro.posicaoveiculo.x + ((25) * cos(rotacao) - (50) * sin(rotacao)) , carro.posicaoveiculo.y + ((25) * sin(rotacao) + (50) * cos(rotacao))};
        Vector2 AD = {carro.posicaoveiculo.x + ((25) * cos(rotacao) - (0) * sin(rotacao)) , carro.posicaoveiculo.y + ((25) * sin(rotacao) + (0) * cos(rotacao))};
        Vector2 CD = {carro.posicaoveiculo.x + ((0) * cos(rotacao) - (50) * sin(rotacao)) , carro.posicaoveiculo.y + ((0) * sin(rotacao) + (50) * cos(rotacao))};
        Vector2 BC = {carro.posicaoveiculo.x + ((-25) * cos(rotacao) - (0) * sin(rotacao)) , carro.posicaoveiculo.y + ((-25) * sin(rotacao) + (0) * cos(rotacao))};
        Vector2 AB = {carro.posicaoveiculo.x + ((0) * cos(rotacao) - (-50) * sin(rotacao)) , carro.posicaoveiculo.y + ((0) * sin(rotacao) + (-50) * cos(rotacao))};

        for(int i=0 ; i<numero_nitros ; i++){
            if(CheckCollisionPointRec(A, jumpers[i])) pegou = 1;
            if(CheckCollisionPointRec(B, jumpers[i])) pegou = 1;
            if(CheckCollisionPointRec(C, jumpers[i])) pegou = 1;
            if(CheckCollisionPointRec(D, jumpers[i])) pegou = 1;
            if(CheckCollisionPointRec(AD, jumpers[i])) pegou = 1;
            if(CheckCollisionPointRec(CD, jumpers[i])) pegou = 1;
            if(CheckCollisionPointRec(BC, jumpers[i])) pegou = 1;
            if(CheckCollisionPointRec(AB, jumpers[i])) pegou = 1;
        }

    }

    else  if(direcao == 8 || direcao == 6){

        float rotacao = 135.0f;

        Vector2 A = {carro.posicaoveiculo.x + ((25) * cos(rotacao) - (-50) * sin(rotacao)) , carro.posicaoveiculo.y + ((25) * sin(rotacao) + (-50) * cos(rotacao))};
        Vector2 B = {carro.posicaoveiculo.x + ((-25) * cos(rotacao) - (-50) * sin(rotacao)) , carro.posicaoveiculo.y + ((-25) * sin(rotacao) + (-50) * cos(rotacao))};
        Vector2 C = {carro.posicaoveiculo.x + ((-25) * cos(rotacao) - (50) * sin(rotacao)), carro.posicaoveiculo.y + ((-25) * sin(rotacao) + (50) * cos(rotacao))};
        Vector2 D = {carro.posicaoveiculo.x + ((25) * cos(rotacao) - (50) * sin(rotacao)) , carro.posicaoveiculo.y + ((25) * sin(rotacao) + (50) * cos(rotacao))};
        Vector2 AD = {carro.posicaoveiculo.x + ((25) * cos(rotacao) - (0) * sin(rotacao)) , carro.posicaoveiculo.y + ((25) * sin(rotacao) + (0) * cos(rotacao))};
        Vector2 CD = {carro.posicaoveiculo.x + ((0) * cos(rotacao) - (50) * sin(rotacao)) , carro.posicaoveiculo.y + ((0) * sin(rotacao) + (50) * cos(rotacao))};
        Vector2 BC = {carro.posicaoveiculo.x + ((-25) * cos(rotacao) - (0) * sin(rotacao)) , carro.posicaoveiculo.y + ((-25) * sin(rotacao) + (0) * cos(rotacao))};
        Vector2 AB = {carro.posicaoveiculo.x + ((0) * cos(rotacao) - (-50) * sin(rotacao)) , carro.posicaoveiculo.y + ((0) * sin(rotacao) + (-50) * cos(rotacao))};

        for(int i=0 ; i<numero_nitros ; i++){
            if(CheckCollisionPointRec(A, jumpers[i])) pegou = 1;
            if(CheckCollisionPointRec(B, jumpers[i])) pegou = 1;
            if(CheckCollisionPointRec(C, jumpers[i])) pegou = 1;
            if(CheckCollisionPointRec(D, jumpers[i])) pegou = 1;
            if(CheckCollisionPointRec(AD, jumpers[i])) pegou = 1;
            if(CheckCollisionPointRec(CD, jumpers[i])) pegou = 1;
            if(CheckCollisionPointRec(BC, jumpers[i])) pegou = 1;
            if(CheckCollisionPointRec(AB, jumpers[i])) pegou = 1;
        }
    }

    return pegou;
}

int pegouMoeda(veiculo carro, Rectangle* nitros, int numero_moedas, int direcao){ 

   int pegou = 0;

    if(direcao == 1 || direcao == 2 || direcao == 3 || direcao == 4){
    for(int i=0 ; i<numero_moedas ; i++){
        if(CheckCollisionRecs(carro.hitboxveiculo, nitros[i])){
            pegou = 1;
        }
    }
    }

    else if(direcao == 5 || direcao == 7){
        float rotacao = 45.0f;

        Vector2 A = {carro.posicaoveiculo.x + ((25) * cos(rotacao) - (-50) * sin(rotacao)) , carro.posicaoveiculo.y + ((25) * sin(rotacao) + (-50) * cos(rotacao))};
        Vector2 B = {carro.posicaoveiculo.x + ((-25) * cos(rotacao) - (-50) * sin(rotacao)) , carro.posicaoveiculo.y + ((-25) * sin(rotacao) + (-50) * cos(rotacao))};
        Vector2 C = {carro.posicaoveiculo.x + ((-25) * cos(rotacao) - (50) * sin(rotacao)), carro.posicaoveiculo.y + ((-25) * sin(rotacao) + (50) * cos(rotacao))};
        Vector2 D = {carro.posicaoveiculo.x + ((25) * cos(rotacao) - (50) * sin(rotacao)) , carro.posicaoveiculo.y + ((25) * sin(rotacao) + (50) * cos(rotacao))};
        Vector2 AD = {carro.posicaoveiculo.x + ((25) * cos(rotacao) - (0) * sin(rotacao)) , carro.posicaoveiculo.y + ((25) * sin(rotacao) + (0) * cos(rotacao))};
        Vector2 CD = {carro.posicaoveiculo.x + ((0) * cos(rotacao) - (50) * sin(rotacao)) , carro.posicaoveiculo.y + ((0) * sin(rotacao) + (50) * cos(rotacao))};
        Vector2 BC = {carro.posicaoveiculo.x + ((-25) * cos(rotacao) - (0) * sin(rotacao)) , carro.posicaoveiculo.y + ((-25) * sin(rotacao) + (0) * cos(rotacao))};
        Vector2 AB = {carro.posicaoveiculo.x + ((0) * cos(rotacao) - (-50) * sin(rotacao)) , carro.posicaoveiculo.y + ((0) * sin(rotacao) + (-50) * cos(rotacao))};

        for(int i=0 ; i<numero_moedas ; i++){
            if(CheckCollisionPointRec(A, nitros[i])) pegou = 1;
            if(CheckCollisionPointRec(B, nitros[i])) pegou = 1;
            if(CheckCollisionPointRec(C, nitros[i])) pegou = 1;
            if(CheckCollisionPointRec(D, nitros[i])) pegou = 1;
            if(CheckCollisionPointRec(AD, nitros[i])) pegou = 1;
            if(CheckCollisionPointRec(CD, nitros[i])) pegou = 1;
            if(CheckCollisionPointRec(BC, nitros[i])) pegou = 1;
            if(CheckCollisionPointRec(AB, nitros[i])) pegou = 1;
        }

    }

    else  if(direcao == 8 || direcao == 6){

        float rotacao = 135.0f;

        Vector2 A = {carro.posicaoveiculo.x + ((25) * cos(rotacao) - (-50) * sin(rotacao)) , carro.posicaoveiculo.y + ((25) * sin(rotacao) + (-50) * cos(rotacao))};
        Vector2 B = {carro.posicaoveiculo.x + ((-25) * cos(rotacao) - (-50) * sin(rotacao)) , carro.posicaoveiculo.y + ((-25) * sin(rotacao) + (-50) * cos(rotacao))};
        Vector2 C = {carro.posicaoveiculo.x + ((-25) * cos(rotacao) - (50) * sin(rotacao)), carro.posicaoveiculo.y + ((-25) * sin(rotacao) + (50) * cos(rotacao))};
        Vector2 D = {carro.posicaoveiculo.x + ((25) * cos(rotacao) - (50) * sin(rotacao)) , carro.posicaoveiculo.y + ((25) * sin(rotacao) + (50) * cos(rotacao))};
        Vector2 AD = {carro.posicaoveiculo.x + ((25) * cos(rotacao) - (0) * sin(rotacao)) , carro.posicaoveiculo.y + ((25) * sin(rotacao) + (0) * cos(rotacao))};
        Vector2 CD = {carro.posicaoveiculo.x + ((0) * cos(rotacao) - (50) * sin(rotacao)) , carro.posicaoveiculo.y + ((0) * sin(rotacao) + (50) * cos(rotacao))};
        Vector2 BC = {carro.posicaoveiculo.x + ((-25) * cos(rotacao) - (0) * sin(rotacao)) , carro.posicaoveiculo.y + ((-25) * sin(rotacao) + (0) * cos(rotacao))};
        Vector2 AB = {carro.posicaoveiculo.x + ((0) * cos(rotacao) - (-50) * sin(rotacao)) , carro.posicaoveiculo.y + ((0) * sin(rotacao) + (-50) * cos(rotacao))};

        for(int i=0 ; i<numero_moedas ; i++){
            if(CheckCollisionPointRec(A, nitros[i])) pegou = 1;
            if(CheckCollisionPointRec(B, nitros[i])) pegou = 1;
            if(CheckCollisionPointRec(C, nitros[i])) pegou = 1;
            if(CheckCollisionPointRec(D, nitros[i])) pegou = 1;
            if(CheckCollisionPointRec(AD, nitros[i])) pegou = 1;
            if(CheckCollisionPointRec(CD, nitros[i])) pegou = 1;
            if(CheckCollisionPointRec(BC, nitros[i])) pegou = 1;
            if(CheckCollisionPointRec(AB, nitros[i])) pegou = 1;
        }
    }

    return pegou;

}

int movimentarCarro1(veiculo* carro1, Rectangle* barreiras){
    
    if(IsKeyDown(KEY_UP)){

        if(IsKeyDown(KEY_LEFT) && IsKeyUp(KEY_RIGHT)){ //movimentando para cima e para esquerda
            (*carro1).posicaoveiculo.x -= (int)((*carro1).velocidade / sqrt(2));
            (*carro1).posicaoveiculo.y -= (int)((*carro1).velocidade / sqrt(2));
            (*carro1).hitboxveiculo.x -= (int)((*carro1).velocidade / sqrt(2));
            (*carro1).hitboxveiculo.y -= (int)((*carro1).velocidade / sqrt(2));

            if(colidiu(*carro1, barreiras, numero_bordas, 8) == 1){
                (*carro1).posicaoveiculo.x += (int)((*carro1).velocidade / sqrt(2));
                (*carro1).posicaoveiculo.y += (int)((*carro1).velocidade / sqrt(2));
                (*carro1).hitboxveiculo.x += (int)((*carro1).velocidade / sqrt(2));
                (*carro1).hitboxveiculo.y += (int)((*carro1).velocidade / sqrt(2));
            }

            return 8;
        }

        else if(IsKeyDown(KEY_RIGHT) && IsKeyUp(KEY_LEFT)){ //movimentando para cima e para direita
            (*carro1).posicaoveiculo.x += (int)((*carro1).velocidade / sqrt(2));
            (*carro1).posicaoveiculo.y -= (int)((*carro1).velocidade / sqrt(2));
            (*carro1).hitboxveiculo.x += (int) ((*carro1).velocidade / sqrt(2));
            (*carro1).hitboxveiculo.y -= (int) ((*carro1).velocidade / sqrt(2));

            if(colidiu(*carro1, barreiras, numero_bordas, 5) == 1){
                (*carro1).posicaoveiculo.x -= (int)((*carro1).velocidade / sqrt(2));
                (*carro1).posicaoveiculo.y += (int)((*carro1).velocidade / sqrt(2));
                (*carro1).hitboxveiculo.x -= (int) ((*carro1).velocidade / sqrt(2));
                (*carro1).hitboxveiculo.y += (int) ((*carro1).velocidade / sqrt(2));
            }

            return 5;
        }

        else if(IsKeyUp(KEY_DOWN) && IsKeyDown(KEY_UP)){ //movimentando para cima apenas
            (*carro1).posicaoveiculo.y -= (int)(*carro1).velocidade;

            //mudando a hitbox (carro ficara na vertical):
            (*carro1).hitboxveiculo.x = (int)(*carro1).posicaoveiculo.x - 25; 
            (*carro1).hitboxveiculo.y = (int) (*carro1).posicaoveiculo.y - 50;
            (*carro1).hitboxveiculo.width = 50;
            (*carro1).hitboxveiculo.height = 100;

            if(colidiu(*carro1, barreiras, numero_bordas, 1) == 1){
                (*carro1).posicaoveiculo.y += (int)(*carro1).velocidade;
                (*carro1).hitboxveiculo.y += (int)(*carro1).velocidade; 
            }

            return 1;
        }
    }

    else if(IsKeyDown(KEY_DOWN)){

        if(IsKeyDown(KEY_LEFT) && IsKeyUp(KEY_RIGHT)){ //movimentando para baixo e para esquerda
            (*carro1).posicaoveiculo.x -= (int)((*carro1).velocidade / sqrt(2));
            (*carro1).posicaoveiculo.y += (int)((*carro1).velocidade / sqrt(2));
            (*carro1).hitboxveiculo.x -= (int)((*carro1).velocidade / sqrt(2));
            (*carro1).hitboxveiculo.y += (int)((*carro1).velocidade / sqrt(2));

            if(colidiu(*carro1, barreiras, numero_bordas, 7) == 1){
                (*carro1).posicaoveiculo.x += (int)((*carro1).velocidade / sqrt(2));
                (*carro1).posicaoveiculo.y -= (int)((*carro1).velocidade / sqrt(2));
                (*carro1).hitboxveiculo.x += (int)((*carro1).velocidade / sqrt(2));
                (*carro1).hitboxveiculo.y -= (int)((*carro1).velocidade / sqrt(2));
            }

            return 7;
        }

        else if(IsKeyDown(KEY_RIGHT) && IsKeyUp(KEY_LEFT)){ //movimentando para baixo e para direita
            (*carro1).posicaoveiculo.x += (int)((*carro1).velocidade / sqrt(2));
            (*carro1).posicaoveiculo.y += (int)((*carro1).velocidade / sqrt(2));
            (*carro1).hitboxveiculo.x += (int)((*carro1).velocidade / sqrt(2));
            (*carro1).hitboxveiculo.y += (int)((*carro1).velocidade / sqrt(2));

            if(colidiu(*carro1, barreiras, numero_bordas, 6) == 1){
                (*carro1).posicaoveiculo.x -= (int)((*carro1).velocidade / sqrt(2));
                (*carro1).posicaoveiculo.y -= (int)((*carro1).velocidade / sqrt(2));
                (*carro1).hitboxveiculo.x -= (int)((*carro1).velocidade / sqrt(2));
                (*carro1).hitboxveiculo.y -= (int)((*carro1).velocidade / sqrt(2));
            }

            return 6;
        }

        else if(IsKeyUp(KEY_UP) && IsKeyDown(KEY_DOWN)){ //movimentando para baixo apenas
            (*carro1).posicaoveiculo.y += (int)(*carro1).velocidade;

            //mudando a hitbox (carro ficara na vertical):
            (*carro1).hitboxveiculo.x = (int)(*carro1).posicaoveiculo.x - 25; 
            (*carro1).hitboxveiculo.y = (int) (*carro1).posicaoveiculo.y - 50;
            (*carro1).hitboxveiculo.width = 50;
            (*carro1).hitboxveiculo.height = 100;

            if(colidiu(*carro1, barreiras, numero_bordas, 3) == 1){
                (*carro1).posicaoveiculo.y -= (int)(*carro1).velocidade;
                (*carro1).hitboxveiculo.y -= (int)(*carro1).velocidade;
            }

            return 3;
        }
    }

    else if(IsKeyDown(KEY_RIGHT) && IsKeyUp(KEY_LEFT)){ //movimentando para o lado direito apenas
        (*carro1).posicaoveiculo.x += (int)(*carro1).velocidade;

        //mudando a hitbox (carro ficara na horizontal):
        (*carro1).hitboxveiculo.x = (int)(*carro1).posicaoveiculo.x - 50;
        (*carro1).hitboxveiculo.y = (int)(*carro1).posicaoveiculo.y - 25;
        (*carro1).hitboxveiculo.width = 100;
        (*carro1).hitboxveiculo.height = 50;

        if(colidiu(*carro1, barreiras, numero_bordas, 2) == 1){
            (*carro1).posicaoveiculo.x -= (int)(*carro1).velocidade;
            (*carro1).hitboxveiculo.x -= (int)(*carro1).velocidade;
        }

        return 2;
    }

    else if(IsKeyDown(KEY_LEFT) && IsKeyUp(KEY_RIGHT)){ //movimentando para o lado esquerdo apenas
        (*carro1).posicaoveiculo.x -= (int)(*carro1).velocidade;

        //mudando a hitbox (carro ficara na horizontal):
        (*carro1).hitboxveiculo.x = (int)(*carro1).posicaoveiculo.x - 50;
        (*carro1).hitboxveiculo.y = (int)(*carro1).posicaoveiculo.y - 25;
        (*carro1).hitboxveiculo.width = 100;
        (*carro1).hitboxveiculo.height = 50;

        if(colidiu(*carro1, barreiras, numero_bordas, 4) == 1){
            (*carro1).posicaoveiculo.x += (int)(*carro1).velocidade;
            (*carro1).hitboxveiculo.x += (int)(*carro1).velocidade;
        }

        return 4;
    }

    return 0;
}

int movimentarCarro2(veiculo* carro2, Rectangle* barreiras){
    
    if(IsKeyDown(KEY_W)){

        if(IsKeyDown(KEY_A) && IsKeyUp(KEY_D)){ //movimentando para cima e para esquerda
            (*carro2).posicaoveiculo.x -= (int)((*carro2).velocidade / sqrt(2));
            (*carro2).posicaoveiculo.y -= (int)((*carro2).velocidade / sqrt(2));
            (*carro2).hitboxveiculo.x -= (int)((*carro2).velocidade / sqrt(2));
            (*carro2).hitboxveiculo.y -= (int)((*carro2).velocidade / sqrt(2));

            if(colidiu(*carro2, barreiras, numero_bordas, 8) == 1){
                (*carro2).posicaoveiculo.x += (int)((*carro2).velocidade / sqrt(2));
                (*carro2).posicaoveiculo.y += (int)((*carro2).velocidade / sqrt(2));
                (*carro2).hitboxveiculo.x += (int)((*carro2).velocidade / sqrt(2));
                (*carro2).hitboxveiculo.y += (int)((*carro2).velocidade / sqrt(2));
            }

            return 8;
        }

        else if(IsKeyDown(KEY_D) && IsKeyUp(KEY_A)){ //movimentando para cima e para direita
            (*carro2).posicaoveiculo.x += (int)((*carro2).velocidade / sqrt(2));
            (*carro2).posicaoveiculo.y -= (int)((*carro2).velocidade / sqrt(2));
            (*carro2).hitboxveiculo.x += (int) ((*carro2).velocidade / sqrt(2));
            (*carro2).hitboxveiculo.y -= (int) ((*carro2).velocidade / sqrt(2));

            if(colidiu(*carro2, barreiras, numero_bordas, 5) == 1){
                (*carro2).posicaoveiculo.x -= (int)((*carro2).velocidade / sqrt(2));
                (*carro2).posicaoveiculo.y += (int)((*carro2).velocidade / sqrt(2));
                (*carro2).hitboxveiculo.x -= (int) ((*carro2).velocidade / sqrt(2));
                (*carro2).hitboxveiculo.y += (int) ((*carro2).velocidade / sqrt(2));
            }

            return 5;
        }

        else if(IsKeyUp(KEY_S) && IsKeyDown(KEY_W)){ //movimentando para cima apenas
            (*carro2).posicaoveiculo.y -= (int)(*carro2).velocidade;

            //mudando a hitbox (carro ficara na vertical):
            (*carro2).hitboxveiculo.x = (int)(*carro2).posicaoveiculo.x - 25; 
            (*carro2).hitboxveiculo.y = (int) (*carro2).posicaoveiculo.y - 50;
            (*carro2).hitboxveiculo.width = 50;
            (*carro2).hitboxveiculo.height = 100;

            if(colidiu(*carro2, barreiras, numero_bordas, 1) == 1){
                (*carro2).posicaoveiculo.y += (int)(*carro2).velocidade;
                (*carro2).hitboxveiculo.y += (int)(*carro2).velocidade; 
            }

            return 1;
        }
    }

    else if(IsKeyDown(KEY_S)){

        if(IsKeyDown(KEY_A) && IsKeyUp(KEY_D)){ //movimentando para baixo e para esquerda
            (*carro2).posicaoveiculo.x -= (int)((*carro2).velocidade / sqrt(2));
            (*carro2).posicaoveiculo.y += (int)((*carro2).velocidade / sqrt(2));
            (*carro2).hitboxveiculo.x -= (int)((*carro2).velocidade / sqrt(2));
            (*carro2).hitboxveiculo.y += (int)((*carro2).velocidade / sqrt(2));

            if(colidiu(*carro2, barreiras, numero_bordas, 7) == 1){
                (*carro2).posicaoveiculo.x += (int)((*carro2).velocidade / sqrt(2));
                (*carro2).posicaoveiculo.y -= (int)((*carro2).velocidade / sqrt(2));
                (*carro2).hitboxveiculo.x += (int)((*carro2).velocidade / sqrt(2));
                (*carro2).hitboxveiculo.y -= (int)((*carro2).velocidade / sqrt(2));
            }

            return 7;
        }

        else if(IsKeyDown(KEY_D) && IsKeyUp(KEY_A)){ //movimentando para baixo e para direita
            (*carro2).posicaoveiculo.x += (int)((*carro2).velocidade / sqrt(2));
            (*carro2).posicaoveiculo.y += (int)((*carro2).velocidade / sqrt(2));
            (*carro2).hitboxveiculo.x += (int)((*carro2).velocidade / sqrt(2));
            (*carro2).hitboxveiculo.y += (int)((*carro2).velocidade / sqrt(2));

            if(colidiu(*carro2, barreiras, numero_bordas, 6) == 1){
                (*carro2).posicaoveiculo.x -= (int)((*carro2).velocidade / sqrt(2));
                (*carro2).posicaoveiculo.y -= (int)((*carro2).velocidade / sqrt(2));
                (*carro2).hitboxveiculo.x -= (int)((*carro2).velocidade / sqrt(2));
                (*carro2).hitboxveiculo.y -= (int)((*carro2).velocidade / sqrt(2));
            }

            return 6;
        }

        else if(IsKeyUp(KEY_W) && IsKeyDown(KEY_S)){ //movimentando para baixo apenas
            (*carro2).posicaoveiculo.y += (int)(*carro2).velocidade;

            //mudando a hitbox (carro ficara na vertical):
            (*carro2).hitboxveiculo.x = (int)(*carro2).posicaoveiculo.x - 25; 
            (*carro2).hitboxveiculo.y = (int) (*carro2).posicaoveiculo.y - 50;
            (*carro2).hitboxveiculo.width = 50;
            (*carro2).hitboxveiculo.height = 100;

            if(colidiu(*carro2, barreiras, numero_bordas, 3) == 1){
                (*carro2).posicaoveiculo.y -= (int)(*carro2).velocidade;
                (*carro2).hitboxveiculo.y -= (int)(*carro2).velocidade;
            }

            return 3;
        }
    }

    else if(IsKeyDown(KEY_D) && IsKeyUp(KEY_A)){ //movimentando para o lado direito apenas
        (*carro2).posicaoveiculo.x += (int)(*carro2).velocidade;

        //mudando a hitbox (carro ficara na horizontal):
        (*carro2).hitboxveiculo.x = (int)(*carro2).posicaoveiculo.x - 50;
        (*carro2).hitboxveiculo.y = (int)(*carro2).posicaoveiculo.y - 25;
        (*carro2).hitboxveiculo.width = 100;
        (*carro2).hitboxveiculo.height = 50;

        if(colidiu(*carro2, barreiras, numero_bordas, 2) == 1){
            (*carro2).posicaoveiculo.x -= (int)(*carro2).velocidade;
            (*carro2).hitboxveiculo.x -= (int)(*carro2).velocidade;
        }

        return 2;
    }

    else if(IsKeyDown(KEY_A) && IsKeyUp(KEY_D)){ //movimentando para o lado esquerdo apenas
        (*carro2).posicaoveiculo.x -= (int)(*carro2).velocidade;

        //mudando a hitbox (carro ficara na horizontal):
        (*carro2).hitboxveiculo.x = (int)(*carro2).posicaoveiculo.x - 50;
        (*carro2).hitboxveiculo.y = (int)(*carro2).posicaoveiculo.y - 25;
        (*carro2).hitboxveiculo.width = 100;
        (*carro2).hitboxveiculo.height = 50;

        if(colidiu(*carro2, barreiras, numero_bordas, 4) == 1){
            (*carro2).posicaoveiculo.x += (int)(*carro2).velocidade;
            (*carro2).hitboxveiculo.x += (int)(*carro2).velocidade;
        }

        return 4;
    }

    return 0;
}
