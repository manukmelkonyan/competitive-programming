#include <bits/stdc++.h>
using namespace std;

// Apartments
// https://cses.fi/problemset/task/1084

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> desired_sizes(n);
    vector<int> apartment_sizes(m);

    for (int i = 0; i < n; i++)
    {
        cin >> desired_sizes[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> apartment_sizes[i];
    }
    
    sort(desired_sizes.begin(), desired_sizes.end());
    sort(apartment_sizes.begin(), apartment_sizes.end());

    
    int count = 0;
    int i = 0;
    int j = 0;

    while (i < n && j < m) {
        if (desired_sizes[i] < apartment_sizes[j] - k) {
            i++;
        }
        else if (desired_sizes[i] > apartment_sizes[j] + k){
            j++;
        }
        else {
            count++;
            i++;
            j++;
        }
    }

    cout << count << '\n';

    return 0;
}
