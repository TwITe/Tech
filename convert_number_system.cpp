#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

const int base = 10;

void print_big_num(const vector<char>& number) {
    for (int i = (int) number.size() - 1; i >= 0; i--) {
        cout << number[i];
    }
    cout << endl;
}

void save_big_num(const string& s, vector<char>& a) {
    for (int i = (int) s.size() - 1; i >= 0; i--) {
        a.push_back(s[i]);
    }
}

void save_big_num(const string& s, vector<int>& a) {
    for (int i = (int)s.size() - 1; i >= 0; i--) {
        a.push_back(s[i] - '0');
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

void multiplicate_big_nums(const vector<int>& a, const vector<int>& b, vector<int>& c) { // умножение длинного на длинное
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

void divide_long_num(vector<int>& a, ll b, int& carry) {
    for (int i = (int) a.size() - 1; i >= 0; i--) {
        long long cur = a[i] + carry * 1ll * base;
        a[i] = int(cur / b);
        carry = int(cur % b);
    }
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
}


void solve() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<char, int> bin;
    for (int a = 0; a < 10; a++) {
        bin[a + '0'] = a;
    }
    int cnt = 10;
    for (char a = 'A'; a <= 'Z'; a++) {
        bin[a] = cnt;
        cnt++;
    }

    map<int, char> bin1;
    char z = 'A';
    for (int i = 10; i < 36; i++) {
        bin1[i] = z;
        z++;
    }

    int a, b;
    string s;
    cin >> a >> b >> s;

    vector<int> v;
    save_big_num(s, v);

    reverse(s.begin(), s.end());

    vector<int> ans[s.size()];

    if (a != 10) { // перевод в десятичную систему
        vector<int> cur;
        string curstr = to_string(a);
        save_big_num(curstr, cur);
        for (int i = 0; i < s.size(); i++) {
            int c = bin[s[i]];

            if (i == 0) {
                string i0 = to_string(c);
                save_big_num(i0, ans[i]);
                continue;
            }

            if (i > 1) {
                multiplicate_big_nums(cur, a);
            }

            vector<int> res;
            string resstr = to_string(c);
            save_big_num(resstr, res);

            vector<int> d2;
            multiplicate_big_nums(res, cur, d2);
            res = d2;

            ans[i] = res;
        }
    }

    vector<int> res;
    if (a != 10) {
        res = ans[0];
        for (int i = 1; i < s.size(); i++) {
            add_big_nums(res, ans[i]);
        }
    }
    else {
        res = v;
    }

    string divisor = to_string(b);
    vector<int> div;
    save_big_num(divisor, div);
    vector<int> answer;
    while (compare_big_nums(res, div) >= 0) {
        int remainder = 0;
        divide_long_num(res, b, remainder);
        answer.push_back(remainder);
    }
    int remainder = 0;
    for (int i = 0; i < res.size(); i++) {
        if (i == 0) {
            remainder += res[0];
        }
        else {
            remainder += res[1] * 10;
        }
    }
    answer.push_back(remainder);

    vector<char> convert;
    for (int i = 0; i < answer.size(); i++) {
        if (answer[i] >= 10) {
            convert.push_back(bin1[answer[i]]);
        }
        else {
            convert.push_back(answer[i] + '0');
        }
    }

    print_big_num(convert);
}

int main() {
    solve();
    return 0;
}