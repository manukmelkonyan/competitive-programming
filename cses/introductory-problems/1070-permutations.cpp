#include <bits/stdc++.h>
using namespace std;

// Permutations
// https://cses.fi/problemset/task/1070

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;

    if (n == 1) {
        cout << n;
        return 0;
    }

    if (n <= 3) {
        cout << "NO SOLUTION";
        return 0;
    }

    for (int i = 2; i <= n; i += 2) {
        cout << i << " ";
    }

    for (int i = 1; i <= n; i += 2) {
        cout << i << (n - i <= 1 ? "" : " ");
    }


    return 0;
}
