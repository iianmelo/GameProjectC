#include "raylib.h"

void inicializaCarro(veiculo* carro){
    
    (*carro).velocidade = 2; //velocidade que se alterará caso o nitro esteja ativo
    
    (*carro).posicaoveiculo.x = 540; //posicao na qual o carro inicializado comecara (centro do carro)
    (*carro).posicaoveiculo.y = 360;

    //hitbox:
    (*carro).hitboxveiculo.x = (*carro).posicaoveiculo.x - 25;
    (*carro).hitboxveiculo.y = (*carro).posicaoveiculo.y + 50;
    (*carro).hitboxveiculo.width = 50;
    (*carro).hitboxveiculo.height = 100;

    return;

}

int movimentarCarro1(veiculo* carro1, Rectangle mapa){

    if(IsKeyDown(KEY_W)){

        if(IsKeyDown(KEY_A) && IsKeyUp(KEY_D)){ //movimentando para cima e para esquerda
            (*carro1).posicaoveiculo.x -= (int)((*carro1).velocidade / sqrt(2));
            (*carro1).posicaoveiculo.y -= (int)((*carro1).velocidade / sqrt(2));
            (*carro1).hiboxveiculo.x -= (int)((*carro1).velocidade / sqrt(2));
            (*carro1).hiboxveiculo.y -= (int)((*carro1).velocidade / sqrt(2));
        }

        else if(IsKeyDown(KEY_D) && IsKeyUp(KEY_A)){ //movimentando para cima e para direita
            (*carro1).posicaoveiculo.x += (int)((*carro1).velocidade / sqrt(2));
            (*carro1).posicaoveiculo.y -= (int)((*carro1).velocidade / sqrt(2));
            (*carro1).hitboxveiculo.x += (int) ((*carro1).velocidade / sqrt(2));
            (*carro1).hiboxveiculo.y -= (int) ((*carro1).velocidade / sqrt(2));
        }

        else if(IsKeyUp(KEY_S)){ //movimentando para cima apenas
           (*carro1).posicaoveiculo.y -= (int)(*carro1).velocidade;
           (*carro1).hitboxveiculo.y -= (int)(*carro1).velocidade; 
        }
    }

}

int movimentarCarro2(veiculo* carro2, Rectangle mapa){

    if(IsKeyDown(KEY_UP)){

        if(IsKeyDown(KEY_LEFT) && IsKeyUp(KEY_RIGHT)){ //movimentando para cima e para esquerda
            (*carro2).posicaoveiculo.x -= (int)((*carro2).velocidade / sqrt(2));
            (*carro2).posicaoveiculo.y -= (int)((*carro2).velocidade / sqrt(2));
            (*carro2).hiboxveiculo.x -= (int)((*carro2).velocidade / sqrt(2));
            (*carro2).hiboxveiculo.y -= (int)((*carro2).velocidade / sqrt(2));
        }

        else if(IsKeyDown(KEY_RIGHT) && IsKeyUp(HEY_LEFT)){ //movimentando para cima e para direita
            (*carro2).posicaoveiculo.x += (int)((*carro2).velocidade / sqrt(2));
            (*carro2).posicaoveiculo.y -= (int)((*carro2).velocidade / sqrt(2));
            (*carro2).hitboxveiculo.x += (int) ((*carro2).velocidade / sqrt(2));
            (*carro2).hiboxveiculo.y -= (int) ((*carro2).velocidade / sqrt(2));
        }

        else if(IsKeyUp(KEY_DOWN)){ //movimentando para cima apenas
            (*carro2).posicaoveiculo.y -= (int)(*carro2).velocidade;
            (*carro2).hitboxveiculo.y -= (int)(*carro2).velocidade; 
        }
    }
}
