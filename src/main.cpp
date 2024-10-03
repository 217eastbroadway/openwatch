#include <raylib/raylib.h>
#include <string>
#include <cstdlib>
#include <iostream>

std::string getTimeString() {
    double time = GetTime() + 3650;

    int hour = 0;
    int minute = 0;
    int second = time;
    

    std::string s = std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second);
    return s;
}

int main(){
    InitWindow(800, 550, "[openwatch] | Main Window");
    Font f = LoadFontEx("assets/fonts/helvetica_neue_65.ttf", 30, 0, NULL);

    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTextEx(f, getTimeString().c_str(), {10, 10}, 30, 0, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}