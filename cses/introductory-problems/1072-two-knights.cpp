#include <bits/stdc++.h>
using namespace std;

// Two Knights
// https://cses.fi/problemset/task/1072

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    for (uint64_t k = 1; k <= n; ++k) {
        uint64_t total_combinations = k * k * (k * k - 1) / 2;
        uint64_t attacking_combinations = 4 * (k - 1) * (k - 2); // how many ways to place 2 x 3 and 3 x 2 tiles in the k x k grid (in each tile there are 2 distinct attacking combinations of the knights)
        
        cout << total_combinations - attacking_combinations << endl;
    }

    return 0;
}
