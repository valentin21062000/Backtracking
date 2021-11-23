#define N 6
#include <iostream>
void afisarea(int board[N][N])
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

bool tabel(int board[N][N], int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
    return true;
}

bool NQueen(int board[N][N], int col)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (tabel(board, i, col)) {
            board[i][col] = 1;
            if (NQueen(board, col + 1))
                return true;
            board[i][col] = 0; 
        }
    }

    return false;
}

bool NQ()
{
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };
    if (NQueen(board, 0) == false) {
        printf("Solutia nu exista");
        return false;
    }
    afisarea(board);
    return true;
}
int main()
{
    NQ();
    return 0;
}