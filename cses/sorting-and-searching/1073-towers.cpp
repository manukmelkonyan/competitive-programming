#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Towers
// https://cses.fi/problemset/task/1073

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> cubes(n);
    for(int i = 0; i < n; ++i) {
        cin >> cubes[i];
    }

    vector<int> towers;
    multimap<int, int> top_to_tower;
    
    for(const int cube : cubes) {
        if (top_to_tower.empty() || top_to_tower.upper_bound(cube) == top_to_tower.end()) {
            towers.push_back(cube);
            top_to_tower.insert({ cube, towers.size() - 1 });
        } else {
            auto it = top_to_tower.upper_bound(cube);
            auto [tower_top, tower_idx] = *it;
            top_to_tower.erase(it);
            towers[tower_idx] = cube;
            top_to_tower.insert({ cube, tower_idx });
        }
    }

    cout << towers.size() << '\n';

    return 0;
}
