#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Movie Festival II
// https://cses.fi/problemset/task/1632

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> movies(n); // { end, start }[]
    for(int i = 0; i < n; ++i) {
        cin >> movies[i].second >> movies[i].first;
    }

    sort(movies.begin(), movies.end());

    int last_end = movies.rbegin()->first;
    int count = 0;
    set<pair<int, int>> elapsed;
    for(int i = 0; i < k; ++i) {
        elapsed.insert({ 0, i });
    }

    int movies_watched = 0;
    int j = 0;
    for(int i = 0; i < n; ++i) {
        auto [end, start] = movies[i];
        auto it = elapsed.lower_bound({ start, 0 });
        if (it == elapsed.end()) it--;
        if (it->first > start) {
            if (it == elapsed.begin()) {
                continue;
            }
            it--;
        }
        elapsed.insert({ end, it->second });
        elapsed.erase(it);
        movies_watched++;
    }
    cout << movies_watched << "\n";

    return 0;
}
