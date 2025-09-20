#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Longest Common Subsequence
// https://cses.fi/problemset/task/3403

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<int> nums1(n);
    vector<int> nums2(m);

    for(int i = 0; i < n; ++i) {
        cin >> nums1[i];
    }

    for(int i = 0; i < m; ++i) {
        cin >> nums2[i];
    }

    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(m + 1, { 0, 0 })); // { length_so_far, back_track_dir } 3: diagonal, 2: up, 1: left

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int length_delta = nums1[i - 1] == nums2[j - 1] ? 1 : 0;
            int max_so_far = max({
                dp[i - 1][j].first,
                dp[i][j - 1].first,
                dp[i - 1][j - 1].first + length_delta
            });

            if (length_delta == 1) {
                dp[i][j] = { max_so_far, 3 };
            } else {
                dp[i][j] = { max_so_far, max_so_far == dp[i - 1][j].first ? 2 : 1 };
            }
        }
    }

    vector<int> lcs;

    int i = n, j = m;
    while(i >= 1 && j >= 0) {
        int dir = dp[i][j].second;
        if (dir == 3) {
            lcs.push_back(nums1[i - 1]);
            i--;
            j--;
        } else if (dir == 2) {
            i--;
        }
        else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());

    cout << lcs.size() << '\n';

    for (auto num : lcs) {
        cout << num << ' ';
    }

    cout << '\n';

    return 0;
}
