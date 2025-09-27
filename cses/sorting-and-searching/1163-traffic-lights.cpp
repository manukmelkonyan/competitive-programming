#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Traffic Lights
// https://cses.fi/problemset/task/1163

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, n;
    cin >> x >> n;

    vector<int> traffic_lights(n);
    for(int i = 0; i < n; ++i) {
        cin >> traffic_lights[i];
    }

    set<pair<int, int>> intervals;
    intervals.insert({ 0, x });
    multiset<int> interval_lengths;
    interval_lengths.insert(x);

    for (int traffic_light : traffic_lights) {
        auto it = intervals.upper_bound({ traffic_light, 0 });
        it--;
        auto matching_interval = *it;

        pair<int, int> interval1 = { matching_interval.first, traffic_light };
        pair<int, int> interval2 = { traffic_light, matching_interval.second };

        intervals.erase(it);
        intervals.insert(interval1);
        intervals.insert(interval2);

        interval_lengths.erase(interval_lengths.find(matching_interval.second - matching_interval.first));
        interval_lengths.insert(interval1.second - interval1.first);
        interval_lengths.insert(interval2.second - interval2.first);

        
        cout << *interval_lengths.rbegin() << '\n';
    }


    return 0;
}
