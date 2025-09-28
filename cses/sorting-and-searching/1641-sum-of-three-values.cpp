#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Sum of Three Values
// https://cses.fi/problemset/task/1641

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, target;
    cin >> n >> target;

    vector<pair<int, int>> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i].first;
        nums[i].second = i + 1;
    }

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n - 2; ++i) {
        int left = i + 1;
        int right = n - 1;
        

        int remaining_sum = target - nums[i].first;
        while (left < right) {
            int sum = nums[left].first + nums[right].first;

            if (sum == remaining_sum) {
                cout << nums[i].second << " " << nums[left].second << " " << nums[right].second << "\n";
                return 0;
            }
            if (sum > remaining_sum) {
                right--;
            } else {
                left++;
            }
        }
    }
    cout << "IMPOSSIBLE" << "\n";

    return 0;
}
