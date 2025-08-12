#include <bits/stdc++.h>
using namespace std;

// Repetitions
// https://cses.fi/problemset/task/1069

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string dna;
    cin >> dna;
    char prev_char = 'X';
    int pending_length = 0;
    int max_length = 0;
    for (char c : dna) {
        if (c == prev_char) {
            pending_length++;
        } else {
            pending_length = 1;
            prev_char = c;
        }
        max_length = max(max_length, pending_length);
    }

    cout << max_length;

    return 0;
}
