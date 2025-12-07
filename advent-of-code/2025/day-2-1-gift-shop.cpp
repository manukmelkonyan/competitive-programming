#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Day 2: [Part 1] Gift Shop
// https://adventofcode.com/2025/day/2

int main() {
    string input;
    cin >> input;

    vector<pair<ll, ll>> ranges;

    string_view s = input;
    for (auto part : s | views::split(',')) {
        string r(&*part.begin(), ranges::distance(part));
        auto dash = r.find('-');
        ll start = stoll(string(r.substr(0, dash)));
        ll end = stoll(string(r.substr(dash + 1)));
        ranges.push_back({ start, end });
    }

    auto is_invalid = [](const ll num) -> bool {
        string s = to_string(num);
        if (s.size() % 2 != 0) return false;
        
        int half = s.size() / 2;
        return s.substr(0, half) == s.substr(half, half);
    };

    ll ivalid_ids_sum = 0;
    
    for(auto& [a, b] : ranges) {
        for(ll i = a; i <= b; ++i) {
            if (is_invalid(i)) {
                ivalid_ids_sum += i;
            }
        }
    }

    cout << ivalid_ids_sum << '\n';

    return 0;
}