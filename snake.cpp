#include <iostream>
#include "snake.h"
#include "const.h"
#include "game.h"


int snakeSize = 1;

KEYS actions[(cols - 1) * (rows - 1) - 1]; // нвепедэ опедшдсыху йнлюмд

SHIFT queue[(cols - 1) * (rows - 1) - 1];



char* bornSnake() {
    char* snake = new char[snakeSize + 1];
    for (int i = 0; i < snakeSize; ++i) {
        snake[i] = (i == snakeSize - 1) ? headSymbol : tailSymbol;
        actions[i] = RIGHT;
    }
    for (int i = 0; i < snakeSize - 1; i++)
    {
        queue[i] = left;
    }
    snake[snakeSize] = '\0';

    return snake;
}

void calcQueue() {
    for (int i = 0; i < snakeSize ; ++i) {
        switch (actions[i])
        {
        case LEFT: 
            queue[i] = right;
            break;
        case RIGHT:
            queue[i] = left;
            break;
        case UP:
            queue[i] = down;
            break;
        case DOWN:
            queue[i] = up;
            break;
        }
    }
}

void calcTail(int headRow, int headCol, int & tailRow, int & tailCol)
{
    tailRow = headRow;
    tailCol = headCol;
    for (int i = snakeSize-1; i > 0 ; --i) 
    {
         switch (queue[i])
        {
        case left:
            tailCol -= 1;
            tailCol = tailCol < 1 ? (cols - 2) : tailCol;
            break;
        case right:
            tailCol += 1;
            tailCol = tailCol > (cols - 2) ? 1 : tailCol;
            break;
        case up:
            tailRow -= 1;
            tailRow = tailRow < 1 ? (rows - 2) : tailRow;
            break;
        case down:
            tailRow += 1;
            tailRow = tailRow > (rows - 2) ? 1 : tailRow;
            break;
        }
    }
}