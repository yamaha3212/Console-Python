#include <iostream>
#include <windows.h>
#include "game.h"
#include "field.h"
#include "snake.h"
#include "winconsole.h"
#include <conio.h>

int tailRow=1, tailCol=1;

int headRow = 1; // ��������, ����� ������� ��� ��������
int headCol = snakeSize; // ��� ������ ���� � snake. �� ���������� ��� ���� = 1

bool gameOver = false;
int timeout = 50;

void snakeMov(char** gameField, int direction) {
    switch (direction)
    {
    case RIGHT: { // ����������� ������
        if (actions[snakeSize - 1] != LEFT) { // ���� ���������� ���������� �� ���� ���������������
            if (gameField[headRow][headCol + 1] == 'F') { // ���� ��������� �� ���
                std::swap(gameField[headRow][headCol], gameField[headRow][headCol + 1]);
                gameField[headRow][headCol] = tailSymbol;
                ++headCol;
                ++snakeSize;
                actions[snakeSize - 1] = RIGHT;
                addFood(gameField, cols, rows);
                break;
            }
            for (int i = 0; i < snakeSize - 1; ++i) { // ������� ������� ����������� � ����� ������� ������
                actions[i] = actions[i + 1];
            }
            actions[snakeSize - 1] = RIGHT;
            for (int i = 0; i < snakeSize - 2; ++i) { // ������� ������� ����������� � ����� ������� ������
                queue[i] = queue[i + 1];
            }
            queue[snakeSize - 2] = left;

            if (gameField[headRow][headCol + 1] == borderSymbol) { // ���� ������ ������� ����
               
                std::swap(gameField[headRow][headCol], gameField[headRow][1]);
                std::swap(gameField[headRow][headCol], gameField[tailRow][tailCol]);
                headCol = 1;
                tailCol++;
                calcQueue();
                calcTail(headRow, headCol, tailRow, tailCol);
                break;
            }
            if (gameField[headRow][headCol + 1] == tailSymbol) {
                gameOver = true;
                break;
            }
            else {
                std::swap(gameField[headRow][headCol], gameField[headRow][headCol + 1]);
                std::swap(gameField[headRow][headCol], gameField[tailRow][tailCol]);
                ++headCol;
                calcQueue();
                calcTail(headRow, headCol, tailRow, tailCol);
                break;
            }
    
        }
        else { snakeMov(gameField, LEFT); break; } // ���������, ���� ����� ������ ��������������� �������� ������
    }
    case LEFT: {
        if (actions[snakeSize - 1] != RIGHT) {
            if (gameField[headRow][headCol - 1] == 'F') {
                std::swap(gameField[headRow][headCol], gameField[headRow][headCol - 1]);
                gameField[headRow][headCol] = tailSymbol;
                --headCol;
                ++snakeSize;
                actions[snakeSize - 1] = LEFT;
                addFood(gameField, cols, rows);
                break;
            }
            for (int i = 0; i < snakeSize - 1; ++i) {
                actions[i] = actions[i + 1];
            }
            actions[snakeSize - 1] = LEFT;
           
            for (int i = 0; i < snakeSize - 2; ++i) { // ������� ������� ����������� � ����� ������� ������
                queue[i] = queue[i + 1];
            }
            queue[snakeSize - 2] = right;

            if (gameField[headRow][headCol - 1] == borderSymbol) {
                std::swap(gameField[headRow][headCol], gameField[headRow][cols - 2]);
                std::swap(gameField[headRow][headCol], gameField[tailRow][tailCol]);
                headCol = cols - 2;
                tailCol--;
                calcQueue();
                calcTail(headRow, headCol, tailRow, tailCol);
                break;
            }
            if (gameField[headRow][headCol - 1] == tailSymbol) {
                gameOver = true;
                break;
            }
            else {
                std::swap(gameField[headRow][headCol], gameField[headRow][headCol - 1]);
                std::swap(gameField[headRow][headCol], gameField[tailRow][tailCol]);
                --headCol;
                calcQueue();
                calcTail(headRow, headCol, tailRow, tailCol);
                break;
            }
       
        }
        else { snakeMov(gameField, RIGHT); break; }
    }
    case DOWN: {
        if (actions[snakeSize - 1] != UP) {
            if (gameField[headRow + 1][headCol] == 'F') {
                std::swap(gameField[headRow][headCol], gameField[headRow + 1][headCol]);
                gameField[headRow][headCol] = tailSymbol;
                ++headRow;
                ++snakeSize;
                actions[snakeSize - 1] = DOWN;
                addFood(gameField, cols, rows);
                break;
            }
            for (int i = 0; i < snakeSize - 1; ++i) {
                actions[i] = actions[i + 1];
            }
            actions[snakeSize - 1] = DOWN;

            for (int i = 0; i < snakeSize - 2; ++i) { // ������� ������� ����������� � ����� ������� ������
                queue[i] = queue[i + 1];
            }
            queue[snakeSize - 2] = up;

            if (gameField[headRow + 1][headCol] == borderSymbol) {
                std::swap(gameField[headRow][headCol], gameField[1][headCol]);
                std::swap(gameField[headRow][headCol], gameField[tailRow][tailCol]);
                headRow = 1;
                tailRow++;
                calcQueue();
                calcTail(headRow, headCol, tailRow, tailCol);
                break;
            }
            if (gameField[headRow + 1][headCol] == tailSymbol) {
                gameOver = true;
                break;
            }
            else {
                std::swap(gameField[headRow][headCol], gameField[headRow + 1][headCol]);
                std::swap(gameField[headRow][headCol], gameField[tailRow][tailCol]);
                ++headRow;
                calcQueue();
                calcTail(headRow, headCol, tailRow, tailCol);
                break;
            }
           
        }
        else { snakeMov(gameField, UP); break; }
    }
    case UP: {
        if (actions[snakeSize - 1] != DOWN) {
            if (gameField[headRow - 1][headCol] == 'F') {
                std::swap(gameField[headRow][headCol], gameField[headRow - 1][headCol]);
                gameField[headRow][headCol] = tailSymbol;
                --headRow;
                ++snakeSize;
                actions[snakeSize - 1] = UP;
                addFood(gameField, cols, rows);
                break;
            }
            for (int i = 0; i < snakeSize - 1; ++i) {
                actions[i] = actions[i + 1];
            }
            actions[snakeSize - 1] = UP;
        
            for (int i = 0; i < snakeSize - 2; ++i) { // ������� ������� ����������� � ����� ������� ������
                queue[i] = queue[i + 1];
            }
            queue[snakeSize - 2] = down;

            if (gameField[headRow - 1][headCol] == borderSymbol) {
                std::swap(gameField[headRow][headCol], gameField[rows - 2][headCol]);
                std::swap(gameField[headRow][headCol], gameField[tailRow][tailCol]);
                headRow = rows - 2;
                tailRow--;
                calcQueue();
                calcTail(headRow, headCol, tailRow, tailCol);
                break;
            }
            if (gameField[headRow - 1][headCol] == tailSymbol) {
                gameOver = true;
                break;
            }
            else {
                std::swap(gameField[headRow][headCol], gameField[headRow - 1][headCol]);
                std::swap(gameField[headRow][headCol], gameField[tailRow][tailCol]);
                --headRow;
                calcQueue();
                calcTail(headRow, headCol, tailRow, tailCol);
                break;
            }
        
        }
        else { snakeMov(gameField, DOWN); break; }
    }
    default:
        break;
    }
}


void afterGame() {
    system("cls");
    for (size_t i = 0; i < 55; i++) {
        std::cout << "G a M e O v E r ";
        Sleep(220);
        setCursorPosition(0, 0);
        std::cout << "g A m E o V e R ";
        Sleep(220);
        setCursorPosition(0, 0);
    }
}

void startGame(int delay) {
    char* shake = bornSnake();
    char** gameField = createCanvas(fieldSymbol, borderSymbol, cols, rows, shake, snakeSize);
    addFood(gameField, cols, rows);
    int direction = RIGHT;
    while ( !gameOver ) {
        displayCanvas(gameField, cols, rows);
        DWORD startTime = GetTickCount64();
        DWORD finishTime = startTime + delay;
        while (GetTickCount64() < finishTime)
        {
            Sleep(10);
            if (_kbhit())
            {
                int previousDirection = direction;
                direction = _getch();
                direction = (direction == RIGHT || direction == LEFT || direction == UP || direction == DOWN) ? direction : previousDirection;
            }
        }
        snakeMov(gameField, direction);
        Sleep(delay);
        setCursorPosition(0,0);
    }
    afterGame();
}
