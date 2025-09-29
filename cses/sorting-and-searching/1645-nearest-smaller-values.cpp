#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Nearest Smaller Values
// https://cses.fi/problemset/task/1645

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    stack<pair<int, int>> st;
    vector<int> answers(n);

    for (int i = 0; i < n; ++i) {
        int num = nums[i];
        while(!st.empty() && st.top().first >= num) st.pop();

        if (st.empty()) {
            answers[i] = 0;
        } else {
            answers[i] = st.top().second;
        }
        st.push({ num, i + 1 });
    }

    for(auto nearest_smaller_idx : answers) {
        cout << nearest_smaller_idx << " ";
    }
    cout << "\n";

    return 0;
}
