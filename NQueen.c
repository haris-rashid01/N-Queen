#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define SIZE 2

bool canPlace(int chessBoard[SIZE][SIZE], int row, int columns){
    // Check for queen attack in same row
for (int i = 0; i < columns; i++)
{
    if (chessBoard[row][i])
    {
        return false;
    }
    
}
// Check for queen attack in upper diagonal
for (int i = row, j = columns; i >= 0, j >= 0; i--, j--)
{
    if (chessBoard[i][j])
    {
        return false;
    }
    
}
// Check for queen attack in lower diagonal
for (int i = row, j = columns; i < SIZE, j >= 0; i++, j--)
{
    if (chessBoard[i][j])
    {
        return false;
    }
    
}
return true;
}

void printSolution(int chessBoard[SIZE][SIZE]){
for (int i = 0; i < SIZE; i++)
{
    for (int j = 0; i < SIZE; j++)
    {
        printf("3%d", chessBoard[i][j]);
    }
    printf("\n");

}
}
bool solveForQueens(int chessBoard[SIZE][SIZE], int columns){
if (columns >= SIZE)
{
    return true;
}

for (int i = 0; i < SIZE; i++)
{
    if (canPlace(chessBoard, i, columns))
    {
        chessBoard[i][columns] = 1;
    
    if (solveForQueens(chessBoard, columns + 1)){
        return true; 
    }
    chessBoard[i][columns] = 0;
    }
}
    return false;   
}
bool solveForNQueens(){
int chessBoard[SIZE][SIZE] = {0};

if (!solveForQueens(chessBoard, 0))
{
    printf("Solution cannot be found\n");
    return false;
}
printSolution(chessBoard);
return true;

}

int main(){
printf("The solution is:\n");
solveForNQueens();
return 0;
}