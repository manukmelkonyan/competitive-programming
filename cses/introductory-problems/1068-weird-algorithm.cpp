#include <bits/stdc++.h>
using namespace std;

// Weird Algorithm
// https://cses.fi/problemset/task/1068

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    long long n;
    cin >> n;

    while (n != 1) {
        cout << n << " ";
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
    }

    cout << n;

    return 0;
}
