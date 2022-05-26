#ifndef SNAKE2_FIELD_H
#define SNAKE2_FIELD_H
#include "const.h"

extern int tailPosY;

char** createCanvas(char, char, int, int, const char[], int);
void displayCanvas(char**, int, int);
void addFood(char**, int, int);

#endif //SNAKE2_FIELD_H
