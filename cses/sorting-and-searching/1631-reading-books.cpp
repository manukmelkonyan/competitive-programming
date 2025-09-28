#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>

using namespace std;

// Reading Books
// https://cses.fi/problemset/task/1631

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    
    vector<pii> books(n);
    for(int i = 0; i < n; ++i) {
        cin >> books[i].first;
        books[i].second = i;
    }
    if (n == 1) {
        cout << books[0].first * 2 << "\n";
        return 0;
    }
    
    set<pii, greater<pii>> reader1_rem_books;
    reader1_rem_books.insert(books.begin() + 1, books.end());

    set<pii, greater<pii>> reader2_rem_books;
    reader2_rem_books.insert(books.begin(), books.end());

    ll reader1_timestamp = 0;
    ll reader2_timestamp = 0;

    int reader1_current_book = -1;
    int reader2_current_book = -1;

    while(!reader1_rem_books.empty() && !reader2_rem_books.empty()) {
        if (reader1_timestamp > reader2_timestamp) {
            auto it = reader2_rem_books.begin();
            if (it->second == reader1_current_book && ++it == reader2_rem_books.end()) {
                reader2_timestamp = reader1_timestamp;
                continue;
            }

            reader2_timestamp += it->first;
            reader2_current_book = it->second;
            reader2_rem_books.erase(it);
        } else {
            auto it = reader1_rem_books.begin();
            if (it->second == reader2_current_book && ++it == reader1_rem_books.end()) {
                reader1_timestamp = reader2_timestamp;
                continue;
            }

            reader1_timestamp += it->first;
            reader1_current_book = it->second;
            reader1_rem_books.erase(it);
        }
    }

    while(!reader1_rem_books.empty()) {
        auto it = reader1_rem_books.begin();
        reader1_timestamp += it->first;
        reader1_rem_books.erase(it);
    }

    while(!reader2_rem_books.empty()) {
        auto it = reader2_rem_books.begin();
        reader2_timestamp += it->first;
        reader2_rem_books.erase(it);
    }

    ll min_time_needed = max(reader1_timestamp, reader2_timestamp);

    cout << min_time_needed << "\n";

    return 0;
}
