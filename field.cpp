#include <iostream>
#include "field.h"
#include "const.h"
#include "snake.h"
#include "game.h"
#include <time.h>


char** createCanvas(const char field, const char border, int y, int x, const char snake[], int size) {
    char** canvas = new char* [x];
    for (int i = 0; i < x; ++i) {
        canvas[i] = new char[y];
    }

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            canvas[i][j] = (i == 0 || i == x - 1 || j == 0 || j == y - 1) ? border : field;
        }
    }

    for (int i = 0; i < size; i++)
    {
        canvas[1][i + 1] = snake[i];
    }

    return canvas;
}

void displayCanvas(char** field, int y, int x) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            std::cout << field[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void addFood(char** field, int y, int x) {
    int maxX = x - 1;
    int maxY = y - 1;
    srand(time(NULL));
    int randX = rand() % maxX;
    int randY = rand() % maxY;
    while ( field[randX][randY] == headSymbol || field[randX][randY] == tailSymbol || field[randX][randY] == borderSymbol || field[randX][randY] == 'F')
    {
        randX = rand() % maxX;
        randY = rand() % maxY;
    }
    field[randX][randY] = 'F';
}