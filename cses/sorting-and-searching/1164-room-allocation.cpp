#include <bits/stdc++.h>

#define ll long long

using namespace std;

// Room Allocation
// https://cses.fi/problemset/task/1164

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<tuple<int, int, int>> schedules(n);
    for (int i = 0; i < n; ++i) {
        int arrival, departure;
        cin >> arrival >> departure;

        schedules[i] = { arrival, departure, i };
    }

    sort(schedules.begin(), schedules.end());

    multimap<int, int> departure_to_room; // departure time -> room number
    int rooms_count = 0;
    vector<int> assigned_rooms(n);

    for (int i = 0; i < n; ++i) {
        auto [arrival, departure, index] = schedules[i];
        auto it = departure_to_room.lower_bound(arrival);

        int found_room;

        if (it == departure_to_room.begin()) {
            rooms_count++;
            found_room = rooms_count;
        } else {
            it--;
            int first_empty_room = it->second;
            departure_to_room.erase(it);
            found_room = first_empty_room;
        }

        departure_to_room.insert({ departure, found_room });
        assigned_rooms[index] = found_room;
    }

    cout << rooms_count << "\n";
    for (auto room : assigned_rooms) {
        cout << room << " ";
    }
    cout << "\n";

    return 0;
}
