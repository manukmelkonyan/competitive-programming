#include <bits/stdc++.h>

#define ll long long
#define INF 0x3FFFFFFFFFFFFFFFLL

using namespace std;

// Flight Discount
// https://cses.fi/problemset/task/1195

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({ b, c });
    }
    const int source = 0;
    const int target = n - 1;

    vector<vector<ll>> distance(2, vector<ll>(n, INF)); // [coupon_used][node]
    vector<vector<bool>> processed(2, vector<bool>(n, false)); // [coupon_used][node]

    priority_queue<
        tuple<ll, bool, int>,
        vector<tuple<ll, bool, int>>,
        greater<tuple<ll, bool, int>>
    > pq; // distance, used, node
    pq.push({ 0, false, source  });
    

    while(!pq.empty()) {
        auto [dist, coupon_used, u] = pq.top(); pq.pop();
        if (processed[coupon_used][u]) continue;
        processed[coupon_used][u] = true;
        
        for(auto& [v, w] : adj[u]) {
            ll new_dist = dist + w / 2;
            if (!coupon_used && new_dist < distance[1][v]) {
                distance[1][v] = new_dist;
                pq.push({ new_dist, true, v });
            }
            
            if (dist + w < distance[coupon_used][v]) {
                distance[coupon_used][v] = dist + w;
                pq.push({ dist + w, coupon_used, v });
            }
        }
    }

    cout << distance[1][target] << '\n';

    return 0;
}
