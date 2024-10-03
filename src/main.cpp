#include <raylib/raylib.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <ctime>

std::string getTimeString(time_t time) {
    int seconds = (int)time;
    int minutes = 0;
    int hours = 0;

    if(seconds >= 60) {
        minutes = seconds / 60;
        seconds %= 60;
    }

    if(minutes >= 60) {
        hours = minutes / 60;
        minutes %= 60;
    }

    std::string s = hours < 10 ? '0' + std::to_string(hours) : std::to_string(hours);
    s += ':';
    s += minutes < 10 ? '0' + std::to_string(minutes) : std::to_string(minutes);
    s += ':';
    s += seconds < 10 ? '0' + std::to_string(seconds) : std::to_string(seconds);

    return s;
}

int main(){
    InitWindow(800, 550, "[openwatch] | Main Window");
    Font f = LoadFontEx("assets/fonts/helvetica_neue_65.ttf", 80, 0, NULL);

    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTextEx(f, getTimeString().c_str(), {10, 10}, 80, 0, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}