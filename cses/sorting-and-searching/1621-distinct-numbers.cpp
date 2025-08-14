#include <bits/stdc++.h>
using namespace std;

// Distinct Numbers
// https://cses.fi/problemset/task/1621

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    
    vector<unsigned int> nums(n);
    set<int> distinct_nums;
    
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
        distinct_nums.insert(nums[i]);
    }

    cout << distinct_nums.size() << "\n";

    return 0;
}
