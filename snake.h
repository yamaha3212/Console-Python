#ifndef SNAKE2_SNAKE_H
#define SNAKE2_SNAKE_H

#include "const.h"

extern int snakeSize;

enum SHIFT { zero, up=1, down=2, left=3, right=4 };

extern SHIFT queue[(cols - 1) * (rows - 1) - 1];

extern KEYS actions[(cols - 1) * (rows - 1) - 1];

char* bornSnake();
void calcQueue();
void calcTail(int headRow, int headCol, int& tailRow, int& tailCol);

#endif //SNAKE2_SNAKE_H
