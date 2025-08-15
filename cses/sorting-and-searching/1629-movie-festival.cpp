#include <bits/stdc++.h>
using namespace std;

// Movie Festival
// https://cses.fi/problemset/task/1629

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; ++i) {
        int start, end;
        cin >> start >> end;
        intervals[i] = make_pair(start, end);
    }

    sort(intervals.begin(), intervals.end());

    queue<pair<int, int>> q;
    int res = 0;

    for (int i = 0; i < n; ++i) {
        auto interval = intervals[i];
        auto [start, end] = interval;
        if (!q.empty() && q.front().second <= start) {
            res++;
            while (!q.empty()) q.pop();
        }
        while (!q.empty() && q.front().second > end) {
            q.pop();
        }

        q.push(interval);
    }
    res += q.size() > 0 ? 1 : 0;

    cout << res << '\n';

    return 0;
}
