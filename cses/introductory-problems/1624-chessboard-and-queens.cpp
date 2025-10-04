#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Chessboard and Queens
// https://cses.fi/problemset/task/1624

const int N = 8;

#define RSV 0x80000000

void toggle_queen(vector<vector<int>> &board, int row, int col, int sign) {
    for(int i = 0; i < N; ++i) {
        if (board[i][col] != RSV) board[i][col] += sign;
        if (board[row][i] != RSV) board[row][i] += sign;

        int r, c;
        r = row + i; c = col + i;
        if (r < N && c < N && board[r][c] != RSV) board[r][c] += sign;
        
        r = row - i; c = col + i;
        if (r >= 0 && c < N && board[r][c] != RSV) board[r][c] += sign;
        
        r = row + i; c = col - i;
        if (c >= 0 && r < N && board[r][c] != RSV) board[r][c] += sign;
        
        r = row - i; c = col - i;
        if (r >= 0 && c >= 0 && board[r][c] != RSV) board[r][c] += sign;
        
    }
}

int solve(vector<vector<int>> &board, int starting_row = 0) {
    if (starting_row == N) return 1;

    int result = 0;
    for(int j = 0; j < N; ++j) {
        if (board[starting_row][j] == 0) {
            toggle_queen(board, starting_row, j, 1);
            result += solve(board, starting_row + 1);
            toggle_queen(board, starting_row, j, -1);
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> board(N, vector(N, 0));
    for(int i = 0; i < N; ++i) {
        string row;
        cin >> row;

        for(int j = 0; j < N; ++j) {
            if (row[j] == '*') board[i][j] = RSV;
        }
    }

    cout << solve(board, 0) << "\n";

    return 0;
}
