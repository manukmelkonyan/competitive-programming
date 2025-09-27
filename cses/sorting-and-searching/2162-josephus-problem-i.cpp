#include <bits/stdc++.h>

#define ll long long

using namespace std;

//  Josephus Problem I
// https://cses.fi/problemset/task/2162

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }

    q.push(q.front());
    q.pop();

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();

        if (!q.empty()) {
            q.push(q.front());
            q.pop();
        }
    }
    cout << "\n";

    return 0;
}
