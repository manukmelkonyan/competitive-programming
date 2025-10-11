#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<tuple<int, int, char>> moves = {
    { 0, 1,  'R' },
    { 0, -1, 'L' },
    { 1, 0,  'D' },
    { -1, 0, 'U' },
};

map<int, pair<int, int>> dir_to_back_delta = {
    { 'R', { 0, -1 } },
    { 'L', { 0, 1 }  },
    { 'D', { -1, 0 } },
    { 'U', { 1, 0 }  },
};

// Monsters
// https://cses.fi/problemset/task/1194

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    pair<int, int> start;
    vector<string> grid(n);
    queue<tuple<int, int, int>> self_q;
    queue<tuple<int, int, int>> monsters_q;

    vector<vector<bool>> self_visited(n, vector<bool>(m, false));
    vector<vector<bool>> monsters_visited(n, vector<bool>(m, false));
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            char cell;
            cin >> cell;
            grid[i].push_back(cell);
            switch(cell) {
                case 'M':
                    monsters_q.push({ i, j, 0 });
                    monsters_visited[i][j] = true;
                    break;
                case 'A':
                    start = { i, j };
                    self_q.push({ i, j, 0 });
                    self_visited[i][j] = true;
                    break;
            }
        }
    }

    bool reached_edge = false;
    pair<int, int> end;
    vector<vector<char>> steps(n, vector<char>(m, -1));

    auto is_edge = [&](int i, int j) -> bool {
        return i == 0 || i == n - 1 || j == 0 || j == m - 1;
    };

    auto get_neighbors = [&](int i, int j) -> vector<tuple<int, int, char>> {
        vector<tuple<int, int, char>> neighbors;
        for(auto [x, y, dir] : moves) {
            int new_i = x + i;
            int new_j = y + j;
            if (0 <= new_i && new_i < n && 0 <= new_j && new_j < m) {
                neighbors.push_back({ new_i, new_j, dir });
            }
        }
        return neighbors;
    };

    int current_level = 0;
    while(!self_q.empty() && !reached_edge) {
        if (reached_edge) break;
        
        while(!monsters_q.empty() && get<2>(monsters_q.front()) == current_level) {
            auto [x, y, _] = monsters_q.front(); monsters_q.pop();

            for(auto [i, j, _] : get_neighbors(x, y)) {
                if (grid[i][j] == '#' || monsters_visited[i][j]) continue;
                monsters_visited[i][j] = true;
                monsters_q.push({ i, j, current_level + 1 });
            }
        }

        while(!self_q.empty() && get<2>(self_q.front()) == current_level) {
            auto [x, y, _] = self_q.front(); self_q.pop();

            if (is_edge(x, y)) {
                reached_edge = true;
                end = { x, y };
                break;
            }

            for(auto [i, j, dir] : get_neighbors(x, y)) {
                if (grid[i][j] == '#' || self_visited[i][j] || monsters_visited[i][j]) continue;
                self_visited[i][j] = true;
                self_q.push({ i, j, current_level + 1 });
                steps[i][j] = dir;
            }
        }
        current_level++;
    }

    if (reached_edge) {
        string path;

        auto curr = end;
        while(curr != start) {
            auto [i, j] = curr;
            char dir = steps[i][j];
            auto [x, y] = dir_to_back_delta[dir];
            path.push_back(dir);

            curr = { i + x, j + y };
        }

        reverse(path.begin(), path.end());

        cout << "YES\n" << path.size() << "\n";
        cout << path << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
