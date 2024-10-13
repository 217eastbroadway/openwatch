#include <raylib/raylib.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <thread>

// custom libs
#include <clock.h>

void runTime(Clock& c) {
    while(1) {
        WaitTime(1);
        c.setTime(c.getTime() + 1);
    }
}

int main(){
    Clock c;

    InitWindow(800, 550, "[openwatch] | Main Window");
    Font f = LoadFontEx("assets/fonts/helvetica_neue_65.ttf", 80, 0, 0);

    time_t t = 0;
    std::thread timeThread(runTime, std::ref(c));
    timeThread.detach();

    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTextEx(f, c.getTimeAsString("S : M : H").c_str(), {10, 10}, 80, 0, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}