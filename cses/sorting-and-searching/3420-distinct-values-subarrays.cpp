#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Distinct Values Subarrays
// https://cses.fi/problemset/task/3420

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    int j = 0;

    ll total_count = 0;
    set<int> visited;
    for (int i = 0; i < n; ++i) {
        while(j < n && visited.count(array[j]) == 0) {
            visited.insert(array[j]);
            j++;
            total_count++;
        }

        total_count += (j - i - 1);
        
        visited.erase(array[i]);
    }

    cout << total_count << '\n';

    return 0;
}
