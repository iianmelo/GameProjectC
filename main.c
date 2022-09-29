#include "raylib.h"

int main(){
    int ScreenWidth = 1080;
    int ScreenHeight = 720;
    
    InitWindow(ScreenWidth, ScreenHeight, "JogoDeCorrida");
    SetTargetFPS(60);
    
    //carro 1 (textura e imagens):
    Image carro1 = LoadImage("C:/Users/Ianme/Downloads/craftpix-889156-free-racing-game-kit/PNG/Car_1_Main_Positions/Car_1_01.png");
    ImageResize(&carro1, 50, 100); //deixando o carro menor
    Texture2D carro1textura = LoadTextureFromImage(carro1);  
    
    //carro 2 (textura e imagens):
    Image carro2 = LoadImage("C:/Users/Ianme/Downloads/craftpix-889156-free-racing-game-kit/PNG/Car_3_Main_Positions/Car_3_01.png");
    ImageResize(&carro2, 50, 100); //deixando o carro menor
    Texture2D carro2textura = LoadTextureFromImage(carro2);
    
    float rotacaocarro1 = 0.0f;
    float rotacaocarro2 = 0.0f;
    
    float xcarro1 = ScreenWidth/2 - 30;
    float ycarro1 = ScreenHeight/2 - 30;
        
    float xcarro2 = ScreenWidth/2 + 30;
    float ycarro2 = ScreenHeight/2 + 30;
    
    Vector2 car1Center = {25, 50};
    Vector2 car1Position = {xcarro1, ycarro1}; 
    Rectangle car1Rectangle_source = {0, 0, carro1textura.width, carro1textura.height};
    
    Vector2 car2Center = {25, 50};
    Vector2 car2Position = {xcarro2, ycarro2};
    Rectangle car2Rectangle_source = {0, 0, carro2textura.width, carro2textura.height};
    
    
    //loop principal do jogo
    while(!WindowShouldClose()){
         
        //essas duas variaveis estao no loop pois precisam ser trocadas, de acordo com o teclado
        Rectangle car1Rectangle_destination = {xcarro1, ycarro1, carro1textura.width, carro1textura.height};
        Rectangle car2Rectangle_destination = {xcarro2, ycarro2, carro2textura.width, carro2textura.height};
        
        
        if(IsKeyDown(KEY_RIGHT) && IsKeyUp(KEY_UP) && IsKeyUp(KEY_DOWN)){ // carrinho so indo para a direita
            xcarro1 += 2.0f;
            rotacaocarro1 = 90.0f;
        }
        if(IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_UP)){ //carrinho indo para a direita e para cima
            xcarro1 += 2.0f;
            ycarro1 -= 2.0f;
            rotacaocarro1 = 45.0f;
        }
        if(IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_DOWN)){ //carrinho indo para a direita e para baixo
            xcarro1 += 2.0f;
            ycarro1 += 2.0f;
            rotacaocarro1 = 135.0f;
        }
        if(IsKeyDown(KEY_LEFT) && IsKeyUp(KEY_UP) && IsKeyUp(KEY_DOWN)){ //carrinho so indo para a esquerda
            xcarro1 -= 2.0f;
            rotacaocarro1 = 270.0f;
        }
        if(IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_UP)){ //carrinho indo para a esquerda e para cima
            xcarro1 -= 2.0f;
            ycarro1 -= 2.0f;
            rotacaocarro1 = 315.0f;
        }
        if(IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_DOWN)){ //carrinho indo para a esquerda e para baixo
            ycarro1 += 2.0f;
            xcarro1 -= 2.0f;
            rotacaocarro1 = 225.0f;
        }
        if(IsKeyDown(KEY_UP) && IsKeyUp(KEY_LEFT) && IsKeyUp(KEY_RIGHT)){ //carrinho so indo para cima
            ycarro1 -= 2.0f;
            rotacaocarro1 = 0.0f;
        }
        if(IsKeyDown(KEY_DOWN) && IsKeyUp(KEY_LEFT) && IsKeyUp(KEY_RIGHT)){ //carrinho so indo para baixo
        
            ycarro1 += 2.0f;
            rotacaocarro1 = 180.0f;
        }
        
        if(IsKeyDown(KEY_D) && IsKeyUp(KEY_W) && IsKeyUp(KEY_S)){ // carrinho so indo para a direita
            xcarro2 += 2.0f;
            rotacaocarro2 = 90.0f;
        }
        if(IsKeyDown(KEY_D) && IsKeyDown(KEY_W)){ //carrinho indo para a direita e para cima
            xcarro2 += 2.0f;
            ycarro2 -= 2.0f;
            rotacaocarro2 = 45.0f;
        }
        if(IsKeyDown(KEY_D) && IsKeyDown(KEY_S)){ //carrinho indo para a direita e para baixo
            xcarro2 += 2.0f;
            ycarro2 += 2.0f;
            rotacaocarro2 = 135.0f;
        }
        if(IsKeyDown(KEY_A) && IsKeyUp(KEY_W) && IsKeyUp(KEY_S)){ //carrinho so indo para a esquerda
            xcarro2 -= 2.0f;
            rotacaocarro2 = 270.0f;
        }
        if(IsKeyDown(KEY_A) && IsKeyDown(KEY_W)){ //carrinho indo para a esquerda e para cima
            xcarro2 -= 2.0f;
            ycarro2 -= 2.0f;
            rotacaocarro2 = 315.0f;
        }
        if(IsKeyDown(KEY_A) && IsKeyDown(KEY_S)){ //carrinho indo para a esquerda e para baixo
            ycarro2 += 2.0f;
            xcarro2 -= 2.0f;
            rotacaocarro2 = 225.0f;
        }
        if(IsKeyDown(KEY_W) && IsKeyUp(KEY_A) && IsKeyUp(KEY_D)){ //carrinho so indo para cima
            ycarro2 -= 2.0f;
            rotacaocarro2 = 0.0f;
        }
        if(IsKeyDown(KEY_S) && IsKeyUp(KEY_A) && IsKeyUp(KEY_D)){ //carrinho so indo para baixo
        ycarro2 += 2.0f;
        rotacaocarro2 = 180.0f;
    }
    
    //desenhando:
        BeginDrawing();
        
            ClearBackground(RAYWHITE);
            
            //desenhando centro da tela:
            DrawLine(ScreenWidth/2, 0, ScreenWidth/2, ScreenHeight, BLUE);
            DrawLine(0, ScreenHeight/2, ScreenWidth, ScreenHeight/2, BLUE);
        
            //desenhando modelo do carrinho 1:
            DrawTexturePro(carro1textura, car1Rectangle_source, car1Rectangle_destination, car1Center, rotacaocarro1, RAYWHITE);
            //desenhando modelo do carrinho2:
            DrawTexturePro(carro2textura, car2Rectangle_source, car2Rectangle_destination, car2Center, rotacaocarro2, RAYWHITE);
            
        EndDrawing();
    }
    UnloadTexture(carro1textura);
    UnloadTexture(carro2textura);
    CloseWindow();
    return 0;
   
}
