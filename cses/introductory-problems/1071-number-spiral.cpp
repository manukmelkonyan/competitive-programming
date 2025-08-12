#include <bits/stdc++.h>
using namespace std;

// Number Spiral
// https://cses.fi/problemset/task/1071

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        uint64_t y, x;
        cin >> y >> x;
        
        uint64_t res;
        if (y <= x) {
            if (x % 2 == 0) {
                res = (x - 1) * (x - 1) + y;
            }
            else {
                res = x * x - y + 1;
            }
        } else {
            if (y % 2 == 0) {
                res = y * y - x + 1;
            }
            else {
                res = (y - 1) * (y - 1) + x;
            }
        }
        cout << res << endl;
    }

    return 0;
}
