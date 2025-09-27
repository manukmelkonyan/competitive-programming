#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Nested Ranges Check
// https://cses.fi/problemset/task/2168

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    
    vector<tuple<int, int, int>> ranges(n);
    for(int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        ranges[i] = make_tuple(a, b, i);
    }

    sort(ranges.begin(), ranges.end(), [](auto& a, auto& b) {
        if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
        return get<1>(a) > get<1>(b);
    });

    vector<int> contains(n, 0);
    int min_right_so_far = INT_MAX;
    for(int i = n - 1; i >= 0; --i) {
        auto [l, r, index] = ranges[i];

        if (r >= min_right_so_far) {
            contains[index] = 1;
        }

        min_right_so_far = min(min_right_so_far, r);
    }
    
    vector<int> is_contained(n);
    int max_right_so_far = 0;
    for(int i = 0; i < n; ++i) {
        auto [l, r, index] = ranges[i];

        if (r <= max_right_so_far) {
            is_contained[index] = 1;
        }
        max_right_so_far = max(max_right_so_far, r);
    }
    

    for(auto answer : contains)
        cout << answer << " ";
    cout << "\n";

    for(auto answer : is_contained)
        cout << answer << " ";
    cout << "\n";
        
    return 0;
}
