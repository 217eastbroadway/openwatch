#include <raylib/raylib.h>
#include <string>
#include <cstdlib>

int main(){
    InitWindow(800, 800, "[openwatch] | Main Window");

    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);

        std::string s = "FPS: " + GetFPS();
        DrawText(s.c_str(), 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}