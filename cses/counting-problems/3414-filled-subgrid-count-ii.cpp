#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Filled Subgrid Count II
// https://cses.fi/problemset/task/3414

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    
    vector<string> grid(n);
    for(int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<ll> nums_of_rectangular_grids(k);

    vector<pair<int, int>> heights(n, { '\0', 0 });

    for(int i = 0; i < n; ++i) {
        stack<vector<ll>> st; // { letter, height, col, count }
        st.push({ '\0', -1, -1, 0  });
        for(int j = 0; j < n; ++j) {
            int letterIdx = grid[i][j] - 'A';
            if (heights[j].first == letterIdx) heights[j].second++;
            else heights[j] = { letterIdx, 1 };

            int height = heights[j].second;

            while(st.top()[0] == letterIdx && st.top()[1] >= height) st.pop();
            ll prev_col = st.top()[2];
            ll prev_count = st.top()[0] == letterIdx ? st.top()[3] : 0;
            ll current = prev_count + (j - prev_col) * height;

            st.push({ letterIdx, height, j, current });
            nums_of_rectangular_grids[letterIdx] += current;
        }
    }

    for(auto num_of_rectangular_grids : nums_of_rectangular_grids) {
        cout << num_of_rectangular_grids << "\n";
    }

    return 0;
}
