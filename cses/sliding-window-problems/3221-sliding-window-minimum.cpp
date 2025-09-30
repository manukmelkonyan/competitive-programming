#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Sliding Window Minimum
// https://cses.fi/problemset/task/3221

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<ll> nums(n);
    nums[0] = x;
    for(int i = 1; i < n; ++i) {
        nums[i] = (a * nums[i - 1] + b) % c;
    }

    deque<pair<ll, int>> min_queue;
    for(int i = 0; i < k; ++i) {
        while (min_queue.size() > 0 && min_queue.back().first >= nums[i]) min_queue.pop_back();
        min_queue.push_back({ nums[i], i });
    }

    ll result = min_queue.front().first;

    for(int i = k; i < n; ++i) {
        while (min_queue.size() > 0 && min_queue.back().first >= nums[i]) min_queue.pop_back();
        if (min_queue.size() > 0 && min_queue.front().second <= i - k) {
            min_queue.pop_front();
        }
        min_queue.push_back({ nums[i], i });
        result ^= min_queue.front().first;
    }

    cout << result << "\n";

    return 0;
}
