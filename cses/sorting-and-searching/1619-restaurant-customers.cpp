#include <bits/stdc++.h>
using namespace std;

// Restaurant Customers
// https://cses.fi/problemset/task/1619

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<int> start_times(n);
    vector<int> end_times(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> start_times[i] >> end_times[i];
    }

    sort(start_times.begin(), start_times.end());
    sort(end_times.begin(), end_times.end());

    int start_i = 0;
    int end_i = 0;

    int max_count = 0;
    int count = 0;

    while (start_i < n) {
        int start_time = start_times[start_i];
        int end_time = end_times[end_i];
        if (start_time < end_time) {
            count++;
            start_i++;
            max_count = max(max_count, count);
        }
        else if (start_time > end_time) {
            count--;
            end_i++;
        }
    }

    cout << max_count << '\n';

    return 0;
}
