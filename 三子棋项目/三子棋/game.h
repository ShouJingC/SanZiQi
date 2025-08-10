#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 10
#define LINE 10
void InitBoard(char arr[ROW][LINE], int row, int line);
void DisplayBorad(char board[ROW][LINE], int row, int line);
void PlayerMove(char board[ROW][LINE]);
void CompMove(char board[ROW][LINE]);
char JudWin(char board[ROW][LINE]);