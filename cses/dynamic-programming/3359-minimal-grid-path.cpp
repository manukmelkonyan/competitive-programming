#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Minimal Grid Path
// https://cses.fi/problemset/task/3359

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<string> grid(n);
    for(int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    queue<pair<int, pair<int, int>>> q; // { distance, { i, j } }
    vector<vector<int>> visited(n, vector<int>(n, 0));
    q.push({ 0, { 0, 0 } });
    visited[0][0] = 1;

    string smallest_path;
    int distance = 0;
    while(!q.empty()) {
        vector<pair<int, int>> best_choices;
        char best_choice = 'Z' + 1;

        while(!q.empty() && q.front().first == distance) {
            auto [i, j] = q.front().second;
            q.pop();
            char cell_value = grid[i][j];
            if (cell_value < best_choice) {
                best_choices.clear();
            }
            if (cell_value <= best_choice) {
                best_choices.push_back({ i, j });
                best_choice = cell_value;
            }
        }
        
        distance++;
        smallest_path.push_back(best_choice);
        for (auto [i, j] : best_choices) {
            if (i + 1 < n && !visited[i + 1][j]) {
                q.push({ distance, { i + 1, j } });
                visited[i + 1][j] = 1;
            }
            if (j + 1 < n && !visited[i][j + 1]) {
                q.push({ distance, { i, j + 1 } });
                visited[i][j + 1] = 1;
            }
        }
    }

    cout << smallest_path << "\n";

    return 0;
}
