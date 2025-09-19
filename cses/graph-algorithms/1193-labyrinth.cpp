#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Labyrinth
// https://cses.fi/problemset/task/1193

const vector<tuple<int, int, char>> moves = {
    { 0,  1, 'R' },
    { 0, -1, 'L' },
    { 1,  0, 'D' },
    { -1, 0, 'U' }
};

const map<char, pair<int, int>> dir_to_source = {
    { 'L', { 0,  1 } },
    { 'R', { 0, -1 } },
    { 'U', { 1,  0 } },
    { 'D', { -1, 0 } }
};


vector<tuple<int, int, char>> get_neighbors(const int& curr_i, const int& curr_j, const int& n, const int& m) {
    vector<tuple<int, int, char>> neighbors;

    for(auto [i, j, dir] : moves) {
        auto x = curr_i + i;
        auto y = curr_j + j;

        if (x >= 0 && x < n && y >= 0 && y < m)
            neighbors.push_back({ x, y, dir });
    }

    return neighbors;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    pair<int, int> start;
    pair<int, int> end;
    for(int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A')
                start = { i, j };
            else if (grid[i][j] == 'B') {
                end = { i, j };
            }
        }
    }

    string result = "NO";
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<char>> steps(n, vector<char>(m));
    queue<pair<int, int>> q;
    q.push(start);
    while(!q.empty()) {
        auto curr = q.front(); q.pop();
        if (curr == end) {
            result = "YES";
            break;
        }

        for(auto [i, j, dir] : get_neighbors(curr.first, curr.second, n, m)) {
            if (!visited[i][j] && grid[i][j] != '#' ) {
                q.push({ i, j });
                steps[i][j] = dir;
                visited[i][j] = true;
            }
        }
    }
    
    cout << result << '\n';
    if (result == "YES") {
        auto curr = end;
        
        string path;
        while(curr != start) {
            auto [i, j] = curr;
            char dir = steps[i][j];
            auto [x, y] = dir_to_source.at(dir);
            path.push_back(dir);
            
            curr = { i + x, j + y };
        }
        reverse(path.begin(), path.end());

        cout << path.size() << '\n';
        cout << path << '\n';
    }

    return 0;
}
