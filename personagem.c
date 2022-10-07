#include "raylib.h"
#include "jogador.h"

void inicializaCarro(veiculo* carro){
    
    (*carro).velocidade = 2; //velocidade que se alterará caso o nitro esteja ativo
    
    (*carro).posicaoveiculo.x = 540; //posicao na qual o carro inicializado comecara (centro do carro)
    (*carro).posicaoveiculo.y = 360;

    //hitbox (com o carro na vertical):
    (*carro).hitboxveiculo.x = (*carro).posicaoveiculo.x - 25;
    (*carro).hitboxveiculo.y = (*carro).posicaoveiculo.y - 50;
    (*carro).hitboxveiculo.width = 50;
    (*carro).hitboxveiculo.height = 100;

    return;

}

int colidiu(veiculo carro, Rectangle* mapa, int numero_bordas){
    int colidiu = 0;
    
    for(int i=0, i<numero_bordas, i++){
        if(CheckCollisionRecs(veiculo.hitboxveiculo, mapa[i])){
            colidiu = 1;
        }
    }

    return colidiu;
}

int movimentarCarro1(veiculo* carro1, Rectangle mapa){
    
    if(IsKeyDown(KEY_UP)){

        if(IsKeyDown(KEY_LEFT) && IsKeyUp(KEY_RIGHT)){ //movimentando para cima e para esquerda
            (*carro1).posicaoveiculo.x -= (int)((*carro1).velocidade / sqrt(2));
            (*carro1).posicaoveiculo.y -= (int)((*carro1).velocidade / sqrt(2));
            (*carro1).hitboxveiculo.x -= (int)((*carro1).velocidade / sqrt(2));
            (*carro1).hitboxveiculo.y -= (int)((*carro1).velocidade / sqrt(2));

            if(colidiu((*carro1), mapa, numero_bordas) == 1){
                (*carro1).posicaoveiculo.x += (int)((*carro1).velocidade / sqrt(2));
                (*carro1).posicaoveiculo.y += (int)((*carro1).velocidade / sqrt(2));
                (*carro1).hitboxveiculo.x += (int)((*carro1).velocidade / sqrt(2));
                (*carro1).hitboxveiculo.y += (int)((*carro1).velocidade / sqrt(2));
            }

            return 8;
        }

        else if(IsKeyDown(KEY_RIGHT) && IsKeyUp(HEY_LEFT)){ //movimentando para cima e para direita
            (*carro1).posicaoveiculo.x += (int)((*carro1).velocidade / sqrt(2));
            (*carro1).posicaoveiculo.y -= (int)((*carro1).velocidade / sqrt(2));
            (*carro1).hitboxveiculo.x += (int) ((*carro1).velocidade / sqrt(2));
            (*carro1).hitboxveiculo.y -= (int) ((*carro1).velocidade / sqrt(2));

            if(colidiu((*carro1), mapa, numero_bordas) == 1){
                (*carro1).posicaoveiculo.x -= (int)((*carro1).velocidade / sqrt(2));
                (*carro1).posicaoveiculo.y += (int)((*carro1).velocidade / sqrt(2));
                (*carro1).hitboxveiculo.x -= (int) ((*carro1).velocidade / sqrt(2));
                (*carro1).hitboxveiculo.y += (int) ((*carro1).velocidade / sqrt(2));
            }

            return 5;
        }

        else if(IsKeyUp(KEY_DOWN)){ //movimentando para cima apenas
            (*carro1).posicaoveiculo.y -= (int)(*carro1).velocidade;

            //mudando a hitbox (carro ficara na vertical):
            (*carro1).hitboxveiculo.x = (int)(*carro1).posicaoveiculo.x - 25; 
            (*carro1).hitboxveiculo.y = (int) (*carro1).posicaoveiculo.y - 50;
            (*carro1).hitboxveiculo.width = 50;
            (*carro1).hitboxveiculo.height = 100;

            if(colidiu((*carro1), mapa, numero_bordas) == 1){
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

            if(colidiu((*carro1), mapa, numero_bordas) == 1){
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

            if(colidiu((*carro1), mapa, numero_bordas) == 1){
                (*carro1).posicaoveiculo.x -= (int)((*carro1).velocidade / sqrt(2));
                (*carro1).posicaoveiculo.y -= (int)((*carro1).velocidade / sqrt(2));
                (*carro1).hitboxveiculo.x -= (int)((*carro1).velocidade / sqrt(2));
                (*carro1).hitboxveiculo.y -= (int)((*carro1).velocidade / sqrt(2));
            }

            return 6;
        }

        else if(IsKeyUp(KEY_UP)){ //movimentando para baixo apenas
            (*carro1).posicaoveiculo.y += (int)(*carro1).velocidade;

            //mudando a hitbox (carro ficara na vertical):
            (*carro1).hitboxveiculo.x = (int)(*carro1).posicaoveiculo.x - 25; 
            (*carro1).hitboxveiculo.y = (int) (*carro1).posicaoveiculo.y - 50;
            (*carro1).hitboxveiculo.width = 50;
            (*carro1).hitboxveiculo.height = 100;

            if(colidiu((*carro1), mapa, numero_bordas) == 1){
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

        if(colidiu((*carro1), mapa, numero_bordas) == 1){
            (*carro1).posicaoveiculo.x -= (int)(*carro1).velocidade;
            (*carro1).hitboxveiculo.x -= (int)(*carro1).velocidade;
        }

        return 2;
    }

    else if(IsKeyDown(KEY_LEFT)){ //movimentando para o lado esquerdo apenas
        (*carro1).posicaoveiculo.x -= (int)(*carro1).velocidade;

        //mudando a hitbox (carro ficara na horizontal):
        (*carro1).hitboxveiculo.x = (int)(*carro1).posicaoveiculo.x - 50;
        (*carro1).hitboxveiculo.y = (int)(*carro1).posicaoveiculo.y - 25;
        (*carro1).hitboxveiculo.width = 100;
        (*carro1).hitboxveiculo.height = 50;

        if(colidiu((*carro1), mapa, numero_bordas) == 1){
            (*carro1).posicaoveiculo.x += (int)(*carro1).velocidade;
            (*carro1).hitboxveiculo.x += (int)(*carro1).velocidade;
        }

        return 4;
    }
}

int movimentarCarro2(veiculo* carro2, Rectangle mapa){

    if(IsKeyDown(KEY_W)){

        if(IsKeyDown(KEY_A) && IsKeyUp(KEY_D)){ //movimentando para cima e para esquerda
            (*carro2).posicaoveiculo.x -= (int)((*carro2).velocidade / sqrt(2));
            (*carro2).posicaoveiculo.y -= (int)((*carro2).velocidade / sqrt(2));
            (*carro2).hitboxveiculo.x -= (int)((*carro2).velocidade / sqrt(2));
            (*carro2).hitboxveiculo.y -= (int)((*carro2).velocidade / sqrt(2));

            if(colidiu((*carro2), mapa, numero_bordas) == 1){
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
            (*carro2).hitboxveiculo.x += (int)((*carro2).velocidade / sqrt(2));
            (*carro2).hitboxveiculo.y -= (int)((*carro2).velocidade / sqrt(2));

            if(colidiu((*carro2), mapa, numero_bordas) == 1){
                (*carro2).posicaoveiculo.x -= (int)((*carro2).velocidade / sqrt(2));
                (*carro2).posicaoveiculo.y += (int)((*carro2).velocidade / sqrt(2));
                (*carro2).hitboxveiculo.x -= (int)((*carro2).velocidade / sqrt(2));
                (*carro2).hitboxveiculo.y += (int)((*carro2).velocidade / sqrt(2));
            }

            return 5;
        }

        else if(IsKeyUp(KEY_S)){ //movimentando para cima apenas
           (*carro2).posicaoveiculo.y -= (int)(*carro2).velocidade;

           //mudando a hitbox (carro ficara na vertical):
            (*carro2).hitboxveiculo.x = (int) (*carro2).posicaoveiculo.x - 25; 
            (*carro2).hitboxveiculo.y = (int) (*carro2).posicaoveiculo.y - 50;
            (*carro2).hitboxveiculo.width = 50;
            (*carro2).hitboxveiculo.height = 100;
           
           if(colidiu((*carro2), mapa, numero_bordas) == 1){
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

            if(colidiu((*carro2), mapa, numero_bordas) == 1){
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

            if(colidiu((*carro2), mapa, numero_bordas) == 1){
                (*carro2).posicaoveiculo.x -= (int)((*carro2).velocidade / sqrt(2));
                (*carro2).posicaoveiculo.y -= (int)((*carro2).velocidade / sqrt(2));
                (*carro2).hitboxveiculo.x -= (int)((*carro2).velocidade / sqrt(2));
                (*carro2).hitboxveiculo.y -= (int)((*carro2).velocidade / sqrt(2));
            }

            return 6;
        }

        else if(IsKeyUp(KEY_W)){ //movimentando para baixo apenas
            (*carro2).posicaoveiculo.y += (int)(*carro2).velocidade;

            //mudando a hitbox (carro ficara na vertical):
            (*carro2).hitboxveiculo.x = (int) (*carro2).posicaoveiculo.x - 25; 
            (*carro2).hitboxveiculo.y = (int) (*carro2).posicaoveiculo.y - 50;
            (*carro2).hitboxveiculo.width = 50;
            (*carro2).hitboxveiculo.height = 100;

            if(colidiu((*carro2), mapa, numero_bordas) == 1){
                (*carro2).posicaoveiculo.y -= (int)(*carro2).velocidade;
                (*carro2).hitboxveiculo.y -= (int)(*carro2).velocidade; 
            }

            return 3;
        }
    }

    else if(IsKeyDown(KEY_D) && IsKeyUp(KEY_A)){ //movimentando para o lado direito apenas
        (*carro2).posicaoveiculo.x += (int)(*carro2).velocidade;
        
        //mudando a hitbox (carro ficara na horizontal):
        (*carro2).hitboxveiculo.x = (int) (*carro2).posicaoveiculo.x - 50; 
        (*carro2).hitboxveiculo.y = (int) (*carro2).posicaoveiculo.y - 25;
        (*carro2).hitboxveiculo.width = 100;
        (*carro2).hitboxveiculo.height = 50;

        if(colidiu((*carro2), mapa, numero_bordas) == 1){
            (*carro2).posicaoveiculo.x -= (int)(*carro2).velocidade;
            (*carro2).hitboxveiculo.x -= (int)(*carro2).velocidade;
        }

        return 2;
    }

    else if(IsKeyDown(KEY_A)){ //movimentando para o lado esquerdo apenas
        (*carro2).posicaoveiculo.x -= (int)(*carro2).velocidade;

        //mudando a hitbox (carro ficara na horizontal):
        (*carro2).hitboxveiculo.x = (int) (*carro2).posicaoveiculo.x - 50; 
        (*carro2).hitboxveiculo.y = (int) (*carro2).posicaoveiculo.y - 25;
        (*carro2).hitboxveiculo.width = 100;
        (*carro2).hitboxveiculo.height = 50;

        if(colidiu((*carro2), mapa, numero_bordas) == 1){
            (*carro2).posicaoveiculo.x += (int)(*carro2).velocidade;
            (*carro2).hitboxveiculo.x += (int)(*carro2).velocidade;
        }

        return 4;
    }
}
