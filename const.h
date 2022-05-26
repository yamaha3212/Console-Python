#ifndef SNAKE2_CONST_H
#define SNAKE2_CONST_H

const int rows = 15;
const int cols = 15 ;
const char tailSymbol = 'o';
const char headSymbol = 'O';
const char fieldSymbol = ' ';
const char borderSymbol = '@';

enum KEYS { LEFT = 97, RIGHT = 100, UP = 119, DOWN = 115, STOP = 27}; // добавить альтернативные варианты управления

#endif //SNAKE2_CONST_H
