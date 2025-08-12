#include <bits/stdc++.h>
using namespace std;

// Coin Piles
// https://cses.fi/problemset/task/1754

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        int64_t a, b;
        cin >> a >> b;

        // linear system of 2 variables (x and y)
        // a - 2x - 1y = 0
        // b - 1x - 2y = 0
        
        // a - 2x -  y = 0 => y = a - 2x
        // b -  x - 2y = 0 => b - x - 2a + 4x = 0 => x = (2a - b) / 3
        if ((2 * a - b) % 3 != 0 || (2 * a - b) < 0) {
            cout << "NO\n";
            continue;
        }
        int64_t x = (2 * a - b) / 3;
        
        int64_t y = a - 2 * x;
        if (y < 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }


    return 0;
}
