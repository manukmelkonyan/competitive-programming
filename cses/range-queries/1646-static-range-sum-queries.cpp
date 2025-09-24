#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Static Range Sum Queries
// https://cses.fi/problemset/task/1646

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }
    
    vector<ll> prefix_sums(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        prefix_sums[i + 1] = nums[i] + prefix_sums[i];
    }

    vector<ll> query_results(q);

    for (int i = 0; i < q; ++i) {
        auto [a, b] = queries[i];

        query_results[i] = prefix_sums[b] - prefix_sums[a - 1];
    }

    for (ll query_result : query_results) {
        cout << query_result << '\n';
    }

    return 0;
}
