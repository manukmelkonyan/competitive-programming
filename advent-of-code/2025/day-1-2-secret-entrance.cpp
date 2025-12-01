#include <bits/stdc++.h>

using namespace std;


// Day 1: [Part 2] Secret Entrance
// https://adventofcode.com/2025/day/1

int main() {
    const int DIAL_CNT = 100;

    int current_dial = 50;

    int password = 0;
    string line;
    while (cin >> line) {
        char direction = line[0];
        int step_count = stoi(line.substr(1));
        
        int steps_before_cycle = direction == 'L' ? current_dial : (DIAL_CNT - current_dial);
    
        if (step_count >= steps_before_cycle) {
            password += (step_count - steps_before_cycle) / DIAL_CNT;
            if (steps_before_cycle > 0) password++;
        }
    
        current_dial += direction == 'L' ?
            DIAL_CNT - step_count % DIAL_CNT :
            step_count;

        current_dial %= DIAL_CNT;
    }

    cout << password << '\n';


    return 0;
}