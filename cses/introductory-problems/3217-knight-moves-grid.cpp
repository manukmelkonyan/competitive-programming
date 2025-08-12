#include <bits/stdc++.h>
using namespace std;

// Knight Moves Grid
// https://cses.fi/problemset/task/3217

constexpr int moves[8][2] = {
    { 1, 2 },
    { 1, -2 },
    { 2, 1 },
    { 2, -1 },
    { -1, 2 },
    { -1, -2 },
    { -2, 1 },
    { -2, -1 },
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<vector<int>> distances(n, vector<int>(n, 0));
    queue<tuple<int, int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    q.push(tuple(0, 0, 0));
    visited[0][0] = true;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        auto [i, j, d] = current;

        distances[i][j] = d;

        for (auto move : moves) {
            int next_i = i + move[0];
            int next_j = j + move[1];
            
            if (next_i >= 0 && next_i < n && next_j >= 0 && next_j < n && !visited[next_i][next_j]) {
                visited[next_i][next_j] = true;
                q.push(tuple(next_i, next_j, d + 1));
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << distances[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
