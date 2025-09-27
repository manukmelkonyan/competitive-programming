#include <bits/stdc++.h>

#define ll long long

constexpr int M = 1e9 + 7;

using namespace std;

// Distinct Values Subsequences
// https://cses.fi/problemset/task/3421

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    
    map<int, int> frequencies;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        auto match = frequencies.find(num);
        if (match == frequencies.end()) {
            frequencies.insert({ num, 1 });
        } else {
            match->second++;
        }

    }
    
    ll result = 1;
    for (auto [_, frequency] : frequencies) {
        result = (result * (frequency + 1)) % M;
    }

    result = (result - 1 + M) % M;

    cout << result % M << '\n';

    return 0;
}
