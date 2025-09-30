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

    deque<int> min_queue;

    ll result = 0;
    for(int i = 0; i < n; ++i) {
        while (!min_queue.empty() && nums[min_queue.back()] >= nums[i])
            min_queue.pop_back();

        min_queue.push_back(i);

        if (min_queue.front() <= i - k)
            min_queue.pop_front();


        if (i >= k - 1) {
            result ^= nums[min_queue.front()];
        }
    }

    cout << result << "\n";

    return 0;
}
