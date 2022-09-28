#include "raylib.h"

int main(){
    int ScreenWidth = 1080;
    int ScreenHeight = 720;
    
    InitWindow(ScreenWidth, ScreenHeight, "JogoDeCorrida");
    SetTargetFPS(60);
    Image carro = LoadImage("C:/Users/Ianme/Downloads/craftpix-889156-free-racing-game-kit/PNG/Car_1_Main_Positions/Car_1_01.png");
    ImageResize(&carro, 50, 100); //deixando o carro menor
    
    Texture2D textura = LoadTextureFromImage(carro);  
    
    float rotacao = 0.0f;
    float TextureX = ScreenWidth/2;
    float TextureY = ScreenHeight/2;
    
    Vector2 carCenter = {25, 50};
    Vector2 carPosition = {TextureX, TextureY}; 
    Rectangle carRectangle_source = {0, 0, textura.width, textura.height};
    
    
    //loop principal do jogo
    while(!WindowShouldClose()){
        
        Rectangle carRectangle_destination = {TextureX, TextureY, textura.width, textura.height};
        
        if(IsKeyDown(KEY_RIGHT) && IsKeyUp(KEY_UP) && IsKeyUp(KEY_DOWN)){ // carrinho so indo para a direita
            TextureX += 2.0f;
            rotacao = 90.0f;
        }
        if(IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_UP)){ //carrinho indo para a direita e para cima
            TextureX += 2.0f;
            TextureY -= 2.0f;
            rotacao = 45.0f;
        }
        if(IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_DOWN)){ //carrinho indo para a direita e para baixo
            TextureX += 2.0f;
            TextureY += 2.0f;
            rotacao = 135.0f;
        }
        if(IsKeyDown(KEY_LEFT) && IsKeyUp(KEY_UP) && IsKeyUp(KEY_DOWN)){ //carrinho so indo para a esquerda
            TextureX -= 2.0f;
            rotacao = 270.0f;
        }
        if(IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_UP)){ //carrinho indo para a esquerda e para cima
            TextureX -= 2.0f;
            TextureY -= 2.0f;
            rotacao = 315.0f;
        }
        if(IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_DOWN)){ //carrinho indo para a esquerda e para baixo
            TextureY += 2.0f;
            TextureX -= 2.0f;
            rotacao = 225.0f;
        }
        if(IsKeyDown(KEY_UP) && IsKeyUp(KEY_LEFT) && IsKeyUp(KEY_RIGHT)){ //carrinho so indo para cima
            TextureY -= 2.0f;
            rotacao = 0.0f;
        }
        if(IsKeyDown(KEY_DOWN) && IsKeyUp(KEY_LEFT) && IsKeyUp(KEY_RIGHT)){ //carrinho so indo para baixo
            TextureY += 2.0f;
            rotacao = 180.0f;
        }
        
        
        //desenhando:
        BeginDrawing();
        
            ClearBackground(RAYWHITE);
            
            //desenhando centro da tela (vou tirar isso no futuro):
            DrawLine(ScreenWidth/2, 0, ScreenWidth/2, ScreenHeight, BLUE);
            DrawLine(0, ScreenHeight/2, ScreenWidth, ScreenHeight/2, BLUE);
        
            //desenhando modelo do carrinho:
            DrawTexturePro(textura, carRectangle_source, carRectangle_destination, carCenter, rotacao, RAYWHITE);
            
        EndDrawing();
        
    }
    
    UnloadTexture(textura);
    CloseWindow();
    return 0;
}
