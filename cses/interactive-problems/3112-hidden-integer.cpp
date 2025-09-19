#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Hidden Integer
// https://cses.fi/problemset/task/3112

int main() {
    ios_base::sync_with_stdio(false);

    int l = 0;
    int r = 1e9;
    int curr;

    while (true) {
        if (l == r) {
            break;
        }
        curr = (l + r) / 2;
        cout << "? " << curr << '\n';
        
        string answer;
        cin >> answer;

        if (answer == "YES") {
            if (curr == r - 1) {
                curr = r;
                break;
            }
            l = curr;
        } else {
            if (curr == l + 1)
                break;
            r = curr;
        }
    }
    cout << "! " << curr << '\n';

    return 0;
}
