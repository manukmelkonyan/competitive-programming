#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Collecting Numbers
// https://cses.fi/problemset/task/2216

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i)
        cin >> nums[i];

    vector<int> indices(n + 1);

    for(int i = 0; i < n; ++i) {
        indices[nums[i]] = i;
    }

    int number_of_rounds = 1;
    for (int i = 1; i < n; ++i) {
        if (indices[i] > indices[i + 1]) {
            number_of_rounds++;
        }
    }

    cout << number_of_rounds << '\n';

    return 0;
}
