#include <bits/stdc++.h>
using namespace std;

// Concert Tickets
// https://cses.fi/problemset/task/1091


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;

    cin >> n >> m;

    vector<int> ticket_prices(n);
    multiset<int> tickets_left;
    vector<int> customer_budgets(m);
    
    for (int i = 0; i < n; ++i) {
        cin >> ticket_prices[i];
        tickets_left.insert(ticket_prices[i]);
    }

    for (int i = 0; i < m; ++i) {
        cin >> customer_budgets[i];
    }

    // sort(ticket_prices.begin(), ticket_prices.end());
    

    for (auto budget : customer_budgets) {
        auto it = tickets_left.upper_bound(budget);
        // auto it = upper_bound(ticket_prices.begin(), ticket_prices.end(), budget);
        if (it == tickets_left.begin()) {
            cout << -1 << '\n';
        } else {
			it--;
            cout << *it << '\n';
            tickets_left.erase(it);

        }
        // int idx = it - ticket_prices.begin() - 1;
        // while (idx >= 0 && used_tickets[idx]) {
        //     idx--;
        // }
        // if (idx < 0) {
        // } else {
        //     used_tickets[idx] = true;
        // }
    }

    return 0;
}
