#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Range Xor Queries
// https://cses.fi/problemset/task/1650

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<pair<int, int>> queries(q);
    for(int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    vector<int> prefix_xor_sums(n + 1);

    for (int i = 0; i < n; ++i) {
        prefix_xor_sums[i + 1] = nums[i] ^ prefix_xor_sums[i];
    }

    vector<int> query_results(q);

    for (int i = 0; i < q; ++i) {
        auto [a, b] = queries[i];

        query_results[i] = prefix_xor_sums[b] ^ prefix_xor_sums[a - 1];
    }

    for (auto query_result : query_results) {
        cout << query_result << '\n';
    }

    return 0;
}
