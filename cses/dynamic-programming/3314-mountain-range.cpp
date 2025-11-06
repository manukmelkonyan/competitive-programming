#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Mountain Range
// https://cses.fi/problemset/task/3314

struct SparseTable {
    int n = 0;
    vector<int> values;
    vector<vector<int>> table; // max indices

    int log_floor(unsigned x) {
        return x == 0 ? -1 : numeric_limits<unsigned>::digits - 1 - countl_zero(x);
    }

    SparseTable(const vector<int>& _values) {
        values = _values;
        n = values.size();
        build_table();
    }

    int max_idx(int a, int b) {
        return values[a] > values[b] ? a : b;
    }

    void build_table() {
        int levels = log_floor(n) + 1;
        table.resize(levels);
        
        for(int k = 0; k < levels; ++k) {
            table[k].resize(n - (1 << k) + 1);
        }

        for(int i = 0; i < n; ++i) {
            table[0][i] = i;
        }

        for(int k = 1; k < levels; ++k) {
            for(int i = 0; i < n - (1 << k) + 1; ++i) {
                table[k][i] = max_idx(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    int query_idx(int a, int b) { // both inclusive
        int level = log_floor(b - a + 1);
        
        return max_idx(table[level][a], table[level][b - (1 << level) + 1]);
    }

    int query(int a, int b) { // both inclusive
        return values[query_idx(a, b)];
    }
};

ll solve(SparseTable& st, int start, int end, int prev_max = -1) {
    if (start > end) return 0;
    int max_idx = st.query_idx(start, end);
    int current_max = st.values[max_idx];

    return (prev_max == current_max ? 0 : 1) + max(solve(st, start, max_idx - 1, current_max), solve(st, max_idx + 1, end, current_max));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    SparseTable st(heights);

    cout << solve(st, 0, n - 1) << '\n';

    return 0;
}
