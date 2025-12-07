#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Day 2: [Part 2] Gift Shop
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
        for (int part = 2; part <= s.size(); ++part) {
            if (s.size() % part != 0) continue;
            int len = s.size() / part;
            string first = s.substr(0, len);
            bool all_equal = true;
            for (int k = 1; k < part; ++k) {
                if (s.substr(k * len, len) != first) {
                    all_equal = false;
                    break;
                }
            }
            if (all_equal) return true;
        }
        return false;
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