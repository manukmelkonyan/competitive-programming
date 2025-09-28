#include <bits/stdc++.h>

#define ll long long
#define ull unsigned ll

using namespace std;

// Factory Machines
// https://cses.fi/problemset/task/1620

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> n >> t;

    vector<int> machines(n);
    for (int i = 0; i < n; ++i) {
        cin >> machines[i];
    }

    sort(machines.begin(), machines.end());
    
    const ull MAX_T = t * machines[0] * machines.size();
    
    ull low = 1;
    ull high = MAX_T;

    ull min_so_far = MAX_T;

    while (low < high) {
        ull time_to_check = (low + high) / 2;

        ull sum = 0;
        for (int i = 0; i < n; ++i) {
            if (machines[i] > time_to_check) break;
            sum += time_to_check / machines[i];
        }
        if (sum >= t) {
            min_so_far = min(min_so_far, time_to_check);
            high = time_to_check;
        } else {
            low = time_to_check + 1;
        }
    }
    
    cout << min_so_far;

    return 0;
}
