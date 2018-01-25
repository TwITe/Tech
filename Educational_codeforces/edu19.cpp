#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

void solve1() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    //--------------
    vector<int> v;

    while (true) {
        bool simple = true;
        if (n % 2 == 0) {
            v.push_back(2);
            n /= 2;
            simple = false;
        }
        else {
            for (int i = 2; i < sqrt(n) + 1; i++) {
                if (n % i == 0) {
                    v.push_back(i);
                    n /= i;
                    simple = false;
                    break;
                }
            }
        }
        if (simple) {
            break;
        }
    }
    if (n != 1) {
        v.push_back(n);
    }

    if (v.size() < k) {
        cout << -1 << endl;
        return;
    }
    if (v.size() == k) {
        for (auto i : v) {
            if (i <= 1) {
                cout << -1 << endl;
                return;
            }
        }
        for (auto i : v) {
            cout << i << " ";
        }
    }
    else {
        while (v.size() > k) {
            int sz = (int)v.size();
            int a = v[sz - 1];
            int b = v[sz - 2];
            v.pop_back();
            v.pop_back();
            v.push_back(a * b);
        }

        for (auto i : v) {
            cout << i << " ";
        }
    }
}

void solve2() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);

    int min_positive = INT_MAX;
    int max_negative = -INT_MAX;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[i] = a;
        if (a > 0) {
            sum += a;
            if (a % 2 != 0) {
                min_positive = min(min_positive, a);
            }
        }
        else if (a < 0) {
            if (a % 2 != 0) {
                max_negative = max(max_negative, a);
            }
        }
    }
    //--------------
    if (sum % 2 == 0) {
        sum -= min(abs(max_negative), min_positive);
    }
    cout << sum;
}

void solve3() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    //-----------
    map<char, int> cnt;
    for (auto i : s) {
        cnt[i]++;
    }
    //-----------
    string u, t;

    int i = 0;
    while (i != s.size()) {
        char cur = s[i];
        t.push_back(cur);
        cnt[cur]--;

        char last = 'z';
        for (auto& it : cnt) {
            if (it.first <= last && it.second > 0) {
                last = it.first;
                break;
            }
        }

        for (int j = (int)t.size() - 1; j >= 0; j--) {
            if (t[j] <= last) {
                u.push_back(t[j]);
                t.pop_back();
            }
            else {
                break;
            }
        }
        i++;
    }

    cout << u << endl;
}

void solve4() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {

    }
}

int main() {
    //solve1();
    //solve2();
    //solve3();
    solve4();
    return 0;
}