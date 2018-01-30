#ifndef TECH_BIG_NUMS_H
#define TECH_BIG_NUMS_H

#include <bits/stdc++.h>
using namespace std;

const int base = 10;

void multiplicate_big_nums(vector<int>& a, int b) { // умножение длинного на короткое
    int carry = 0;
    for (size_t i = 0; i < a.size() || carry; i++) {
        if (i == a.size()) {
            a.push_back(0);
        }
        long long cur = carry + a[i] * b;
        a[i] = int(cur % base);
        carry = int(cur / base);
    }
    while (a.size() > 1 && a.back() == 0) {
        a.pop_back();
    }
}

int compare_big_nums(const vector<int>& a, const vector<int>& b) {
    if (a.size() > b.size()) return 1;
    if (a.size() < b.size()) return -1;

    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] - '0' > b[i] - '0') {
            return 1;
        }
        if (a[i] - '0' < b[i] - '0') {
            return - 1;
        }
    }

    return 0;
}

void print_bug_num(const vector<int>& number) {
    for (int i = number.size() - 1; i >= 0; i--) {
        cout << number[i];
    }
    cout << endl;
}

void save_big_num(vector<int>& a, const string& s) {
    for (int i = (int)s.size() - 1; i >= 0; i--) {
        a.push_back(s[i] - '0');
    }
}

#endif //TECH_BIG_NUMS_H
