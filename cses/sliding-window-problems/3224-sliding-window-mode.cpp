#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>

using namespace std;

// Sliding Window Mode
// https://cses.fi/problemset/task/3224

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    
    map<int, int> window_freq;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (window_freq.find(nums[i]) == window_freq.end()) {
            window_freq.insert({ nums[i], 0 });
        }
    }

    auto freq_item_compare = [](const pii &a, const pii &b) -> bool {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    };
    set<pii, decltype(freq_item_compare)> window_freq_items(freq_item_compare); // { freq, value }

    for(int i = 0; i < n; ++i) {
        int num = nums[i];

        window_freq_items.erase({ window_freq[num], num });
        window_freq_items.insert({ ++window_freq[num], num });
        if (i >= k - 1) {
            auto it = window_freq_items.begin();
            cout << it->second << " ";

            int left_most = nums[i - k + 1];
            window_freq_items.erase({ window_freq[left_most]--, left_most });
            window_freq_items.insert({ window_freq[left_most], left_most });
        }
    }
    cout << "\n";

    return 0;
}
