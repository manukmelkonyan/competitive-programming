#include <bits/stdc++.h>
using namespace std;

#define ll long long

// Two Sets
// https://cses.fi/problemset/task/1092

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    ll sum = n * (n + 1) / 2;

    const int isEven = n % 2 == 0;
    const int first_batch_size = isEven ? 4 : 3;

    if (n <= 2 || sum % 2 != 0 || (n > 4 && (n - first_batch_size) % 4 != 0)) {
        cout << "NO\n";
        return 0;
    }
    
    vector<int> s1;
    vector<int> s2;

    int i = 1;
    if (!isEven) {
        i = 4;
        s1.push_back(1);
        s1.push_back(2);
        s2.push_back(3);
    }
    for (; i <= n; i += 4) {
        s1.push_back(i);
        s1.push_back(i + 3);
        s2.push_back(i + 1);
        s2.push_back(i + 2);
    }

    cout << "YES\n" << s1.size() << "\n";
    for (auto num : s1) {
        cout << num << " ";
    }

    cout << "\n" << s2.size() << "\n";

    for (auto num : s2) {
        cout << num << " ";
    }

    return 0;
}
