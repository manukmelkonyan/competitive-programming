#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Static Range Minimum Queries
// https://cses.fi/problemset/task/1647

struct SparseTable {
    int n = 0;
    vector<int> values;
    vector<vector<int>> table; // holds min indicies;

    int log_floor(unsigned x) {
        return x == 0 ? - 1 : numeric_limits<unsigned>::digits - 1 - countl_zero(x);
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
    int n, q;
    cin >> n >> q;

    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    SparseTable st(nums);

    for(int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        cout << st.query(a, b) << '\n';
    }

    return 0;
}
