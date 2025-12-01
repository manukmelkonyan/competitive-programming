#include <bits/stdc++.h>

using namespace std;


// Day 1: Secret Entrance
// https://adventofcode.com/2025/day/1

int main() {
    const int DIAL_CNT = 100;

    int current_dial = 50;

    int password = 0;
    string line;
    while (cin >> line) {
        char direction = line[0];
        int step_count = stoi(line.substr(1));
    
        current_dial += direction == 'L' ?
            DIAL_CNT - step_count % DIAL_CNT :
            step_count;

        current_dial %= DIAL_CNT;

        if (current_dial == 0) password++;
    }

    cout << password << '\n';


    return 0;
}