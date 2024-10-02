#include <raylib/raylib.h>
#include <string>
#include <cstdlib>

int main(){
    InitWindow(800, 800, "[openwatch] | Main Window");

    Image img = LoadImage("assets/test.png");
    Texture2D texture = LoadTextureFromImage(img);

    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);

        std::string s = "FPS: ";
        DrawText(s.c_str(), 190, 200, 20, LIGHTGRAY);

        
        DrawTexture(texture, 350, 350, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}