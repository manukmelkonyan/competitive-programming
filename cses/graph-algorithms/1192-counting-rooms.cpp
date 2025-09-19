#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Counting Rooms
// https://cses.fi/problemset/task/1192

constexpr pair<int, int> addends[] = {
    make_pair(1, 0),
    make_pair(0, 1),
    make_pair(-1, 0),
    make_pair(0, -1),
};

vector<pair<int, int>> get_neighbors(const pair<int, int> point, const int n, const int m)
{
    vector<pair<int, int>> neighbors;

    for (auto [i, j] : addends) {
        int x = point.first + i;
        int y = point.second + j;
        if (x >= 0 && x < n && y >= 0 && y < m) {
            neighbors.push_back(make_pair(x, y));
        }
    }
    return neighbors;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int number_of_rooms = 0;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (visited[i][j]) continue;
            if (grid[i][j] == '.') {
                number_of_rooms++;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                while (!q.empty()) {
                    auto curr = q.front();
                    q.pop();

                    for (auto neighbor : get_neighbors(curr, n, m)) {
                        auto [x, y] = neighbor;
                        if (!visited[x][y] && grid[x][y] == '.') {
                            visited[x][y] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }
            visited[i][j] = true;
        }

    cout << number_of_rooms << '\n';

    return 0;
}
