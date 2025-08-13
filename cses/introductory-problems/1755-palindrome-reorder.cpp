#include <bits/stdc++.h>
using namespace std;

// Palindrome Reorder
// https://cses.fi/problemset/task/1755

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int alphabet_size = 26;

    int counts[alphabet_size] = {0};
    const int offset = 'A';
    
    string s;
    cin >> s;

    int n = s.size();

    for (auto c : s) {
        counts[c - offset] += 1;
    }

    int odd_idx = -1;

    char* palindrome = new char[n];
    int l_idx = 0;
    int r_idx = n - 1;

    for (int i = 0; i < alphabet_size; ++i) {
        int count = counts[i];
        if (count == 0) continue;
        if (counts[i] % 2 != 0) {
            if (odd_idx != -1) {
                cout << "NO SOLUTION\n";
                return 0;
            }
            odd_idx = i;
        }
        char c = i + offset;
        for (int j = 0; j < count / 2; ++j) {
            palindrome[l_idx++] = c;
            palindrome[r_idx--] = c;
        }
    }

    if (odd_idx != -1) {
        palindrome[n / 2] = odd_idx + offset;
    }

    cout << palindrome << '\n';

    return 0;
}
