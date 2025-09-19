#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Playlist
// https://cses.fi/problemset/task/1141

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> songs(n);
    for(int i = 0; i < n; ++i) {
        cin >> songs[i];
    }
    int max_window = 0;
    int i = 0;
    map<int, int> mp;
    for(int j = 0; j < n; ++j) {
        if (mp.count(songs[j]) == 0) {
            mp.insert({ songs[j], j });
        } else {
            if (mp[songs[j]] >= i) {
                i = mp[songs[j]] + 1;
            }
            mp[songs[j]] = j;
        }
        max_window = max(max_window, j - i + 1);
    }
    
    cout << max_window << '\n';

    return 0;
}
