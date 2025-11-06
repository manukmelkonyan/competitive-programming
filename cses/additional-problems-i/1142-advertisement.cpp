#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Advertisement
// https://cses.fi/problemset/task/1142

struct SparseTable {
    int n = 0;
    vector<int> values;
    vector<vector<int>> table;

    
    static int log_floor(unsigned x) {
        return x == 0 ? -1 : numeric_limits<unsigned>::digits - 1 - countl_zero(x);
    }

    SparseTable(const vector<int>& _values) {
        values = _values;
        n = values.size();
        build_table();
    }

    int min_idx(int a, int b) {
        return values[a] < values[b] ? a : b;
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
                table[k][i] = min_idx(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    int query_idx(int a, int b) {
        int level = log_floor(b - a + 1);
        return min_idx(table[level][a], table[level][b - (1 << level) + 1]);
    }

    int query(int a, int b) {
        return values[query_idx(a, b)];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<int> heights(n);
    for(int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    SparseTable st(heights);

    stack<pair<int, int>> ranges;
    ranges.push({ 0, n - 1 });

    ll max_area = 0;

    while(!ranges.empty()) {
        auto [a, b] = ranges.top(); ranges.pop();

        ll length = b - a + 1;

        int min_idx = st.query_idx(a, b);
        int min_height = heights[min_idx];

        ll area = min_height * length;
        max_area = max(max_area, area);

        if (min_idx > a) {
            ranges.push({ a, min_idx - 1 });
        }

        if (min_idx < b) {
            ranges.push({ min_idx + 1, b });
        }
    }

    cout << max_area << '\n';

    return 0;
}
