#ifndef TECH_BIG_NUMS_H
#define TECH_BIG_NUMS_H

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

const int base = 10;

void multiplicate_big_nums(vector<int>& a, int b) { // умножение длинного на короткое
    int carry = 0;
    for (size_t i = 0; i < a.size() || carry; i++) {
        if (i == a.size()) {
            a.push_back(0);
        }
        long long cur = a[i] * 1ll * b + carry;
        a[i] = int(cur % base);
        carry = int(cur / base);
    }
    while (a.size() > 1 && a.back() == 0) {
        a.pop_back();
    }
}

void multiplicate_big_nums(const vector<int>& a, const vector<int>& b, vector<int>& c) { // умножение длинного на длинное
    // цифры числа a по очереди умножаются на цифры числа b, добавляя прошлый результат
    // обратное умножение (1 цифра числа a умножается 1 цикл на все цифры числа b)
    c.resize(a.size() + b.size());
    for (int i = 0; i < a.size(); i++) {
        int carry = 0;
        for (int j = 0; j < b.size() || carry; j++) {
            long long cur = c[i + j] + a[i] * 1ll * (j < (int) b.size() ? b[j] : 0) + carry;
            c[i + j] = int(cur % base);
            carry = int(cur / base);
        }
    }
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();
}

void divide_long_num(vector<int>& a, ll b, int& carry) {
    for (int i = (int) a.size() - 1; i >= 0; i--) {
        long long cur = a[i] + carry * 1ll * base;
        a[i] = int(cur / b);
        carry = int(cur % b);
    }
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
}

void add_big_nums(vector<int>& a, const vector<int>& b) {
    int carry = 0;
    for (size_t i = 0; i < max(a.size(), b.size()) || carry; i++) {
        if (i == a.size()) {
            a.push_back(0);
        }
        a[i] += carry + (i < b.size() ? b[i] : 0);
        carry = a[i] >= base;
        if (carry) a[i] -= base;
    }
}

void substract_big_nums(vector<int>& a, vector<int>& b) {
    int carry = 0;
    for (size_t i = 0; i < b.size() || carry; i++) {
        a[i] -= carry + (i < b.size() ? b[i] : 0);
        carry = a[i] < 0;
        if (carry) a[i] += base;
    }
    while (a.size() > 1 && a.back() == 0) {
        a.pop_back();
    }
}

int compare_big_nums(vector<int> a, vector<int> b) {
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();

    while (b.size() > 1 && b.back() == 0)
        b.pop_back();

    if (a.size() > b.size()) return 1;
    if (a.size() < b.size()) return -1;

    for (int i = (int) a.size() - 1; i >= 0; i--) {
        if (a[i] - '0' > b[i] - '0') {
            return 1;
        }
        if (a[i] - '0' < b[i] - '0') {
            return -1;
        }
    }
    return 0;
}

bool compare_3big_nums(int& min_num, int& average_num, int& max_num, vector<int>& a, vector<int>& b, vector<int>& c) {
    int res1 = compare_big_nums(a, b);
    int res2 = compare_big_nums(a, c);
    int res3 = compare_big_nums(b, c);

    if (res1 == 0 && res2 == 0 && res3 == 0) {
        return false;
    }

    //find max
    if (res1 >= 0 && res2 >= 0) {
        max_num = 1;
    }
    else if (res1 == -1 && res3 == 1) {
        max_num = 2;
    }
    else {
        max_num = 3;
    }

    //find min
    if (res1 == -1 && res2 == -1) {
        min_num = 1;
    }
    else if (res1 >= 0 && res3 == -1) {
        min_num = 2;
    }
    else {
        min_num = 3;
    }

    //find average
    if ((min_num == 1 && max_num == 3) || (min_num == 3 && max_num == 1)) {
        if (res1 != 0 && res3 != 0) {
            average_num = 2;
        }
    }
    if ((min_num == 2 && max_num == 3) || (min_num == 3 && max_num == 2)) {
        if (res1 != 0 && res2 != 0) {
            average_num = 1;
        }
    }
    if ((min_num == 1 && max_num == 2) || (min_num == 2 && max_num == 1)) {
        if (res2 != 0 && res3 != 0) {
            average_num = 3;
        }
    }

    return true;
}

void print_bug_num(const vector<int>& number) {
    for (int i = (int) number.size() - 1; i >= 0; i--) {
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
