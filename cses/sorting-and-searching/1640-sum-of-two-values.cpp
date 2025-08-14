#include <bits/stdc++.h>
using namespace std;

// Sum of Two Values
// https://cses.fi/problemset/task/1640

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    map<int, int> visited;

    for (int i = 0; i < n; ++i) {
        int num = nums[i];
        auto match = visited.find(target - num);
        if (match != visited.end()) {
            cout << (*match).second + 1 << " " << i + 1 << '\n';
            return 0;
        } else {
            visited.insert(pair(num, i));
        }
    }

    cout << "IMPOSSIBLE" << '\n';

    return 0;
}
