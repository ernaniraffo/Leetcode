#include <stdbool.h>
#include <stdio.h>

void dfs(char** board, int r, int c, int m, int n) {
    if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') {
        return;
    }

    board[r][c] = '1';

    dfs(board, r, c + 1, m, n);
    dfs(board, r, c - 1, m, n);
    dfs(board, r + 1, c, m, n);
    dfs(board, r - 1, c, m, n);
}

void solve(char** board, int boardSize, int* boardColSize) {
    int m = boardSize;
    int n = boardColSize[0];

    for (int c = 0; c < n; c += 1) {
        dfs(board, 0, c, m, n);
        dfs(board, m - 1, c, m, n);
    }

    for (int r = 0; r < m; r += 1) {
        dfs(board, r, 0, m, n);
        dfs(board, r, n - 1, m, n);
    }

    for (int r = 0; r < m; r += 1) {
        for (int c = 0; c < n; c += 1) {
            if (board[r][c] == 'O') {
                board[r][c] = 'X';
            } else if (board[r][c] == '1') {
                board[r][c] = 'O';
            }
        }
    }
}
