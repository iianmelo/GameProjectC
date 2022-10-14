#include "raylib.h"
#include "personagem.h"
#include "animacao.h"
#include <stdbool.h>

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

int colidiu(veiculo carro, Rectangle* barreiras, int numero_bordas){

    int colidiu = 0;
    
    for(int i=0 ; i<numero_bordas ; i++){
        if(CheckCollisionRecs(carro.hitboxveiculo, barreiras[i])){
            colidiu = 1;
        }
    }

    return colidiu;
}

int pegouNitro(veiculo carro, Rectangle* jumpers, int numero_nitros){
    
    int pegou = 0;

    for(int i=0; i<numero_nitros; i++){
        if(CheckCollisionRecs(carro.hitboxveiculo, jumpers[i])){
            pegou = 1;
        }
    }

    return pegou;
}

int pegouMoeda(veiculo carro, Rectangle* nitros, int numero_moedas){ 

    int pegou = 0;

    for(int i=0 ; i<numero_moedas ; i++){
        if(CheckCollisionRecs(carro.hitboxveiculo, nitros[i])){
            pegou = 1;
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

            if(colidiu(*carro1, barreiras, numero_bordas) == 1){
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

            if(colidiu(*carro1, barreiras, numero_bordas) == 1){
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

            if(colidiu(*carro1, barreiras, numero_bordas) == 1){
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

            if(colidiu(*carro1, barreiras, numero_bordas) == 1){
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

            if(colidiu(*carro1, barreiras, numero_bordas) == 1){
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

            if(colidiu(*carro1, barreiras, numero_bordas) == 1){
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

        if(colidiu(*carro1, barreiras, numero_bordas) == 1){
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

        if(colidiu(*carro1, barreiras, numero_bordas) == 1){
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

            if(colidiu(*carro2, barreiras, numero_bordas) == 1){
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

            if(colidiu(*carro2, barreiras, numero_bordas) == 1){
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

            if(colidiu(*carro2, barreiras, numero_bordas) == 1){
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

            if(colidiu(*carro2, barreiras, numero_bordas) == 1){
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

            if(colidiu(*carro2, barreiras, numero_bordas) == 1){
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

            if(colidiu(*carro2, barreiras, numero_bordas) == 1){
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

        if(colidiu(*carro2, barreiras, numero_bordas) == 1){
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

        if(colidiu(*carro2, barreiras, numero_bordas) == 1){
            (*carro2).posicaoveiculo.x += (int)(*carro2).velocidade;
            (*carro2).hitboxveiculo.x += (int)(*carro2).velocidade;
        }

        return 4;
    }

    return 0;
}
