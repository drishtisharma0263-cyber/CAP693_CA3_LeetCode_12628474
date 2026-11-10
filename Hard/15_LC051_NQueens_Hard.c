#include <stdlib.h>
#include <string.h>

char ***ans;
int count;
int N;
int *cols, *diag1, *diag2;
char **board;

void solve(int row)
{
    int i, j;

    if (row == N)
    {
        ans[count] = (char **)malloc(N * sizeof(char *));

        for (i = 0; i < N; i++)
        {
            ans[count][i] = (char *)malloc((N + 1) * sizeof(char));
            strcpy(ans[count][i], board[i]);
        }

        count++;
        return;
    }

    for (j = 0; j < N; j++)
    {
        if (cols[j] == 0 &&
            diag1[row - j + N - 1] == 0 &&
            diag2[row + j] == 0)
        {
            board[row][j] = 'Q';

            cols[j] = 1;
            diag1[row - j + N - 1] = 1;
            diag2[row + j] = 1;

            solve(row + 1);

            board[row][j] = '.';

            cols[j] = 0;
            diag1[row - j + N - 1] = 0;
            diag2[row + j] = 0;
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes)
{
    int i, j;

    N = n;
    count = 0;

    ans = (char ***)malloc(400 * sizeof(char **));

    board = (char **)malloc(N * sizeof(char *));

    for (i = 0; i < N; i++)
    {
        board[i] = (char *)malloc((N + 1) * sizeof(char));

        for (j = 0; j < N; j++)
            board[i][j] = '.';

        board[i][N] = '\0';
    }

    cols = (int *)calloc(N, sizeof(int));
    diag1 = (int *)calloc(2 * N - 1, sizeof(int));
    diag2 = (int *)calloc(2 * N - 1, sizeof(int));

    solve(0);

    *returnSize = count;

    *returnColumnSizes = (int *)malloc(count * sizeof(int));

    for (i = 0; i < count; i++)
        (*returnColumnSizes)[i] = N;

    return ans;
}
