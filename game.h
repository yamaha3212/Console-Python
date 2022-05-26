#ifndef SNAKE2_GAME_H
#define SNAKE2_GAME_H

extern bool gameOver;
extern int timeout;

extern int headRow;
extern int headCol;

void snakeMov(char**, int);
void afterGame();
void startGame(int);

#endif //SNAKE2_GAME_H
