#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

void solve1() { // Problem A
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        v[i] = a;
    }
    //----------
    sort(v.begin(), v.end());

    ll x = LONG_LONG_MAX;
    int cnt = 1;
    for (int i = n - 1; i > 0; i--) {
        ll l = abs(v[i] - v[i - 1]);
        if (l == x) {
            cnt++;
        }
        else if (l < x) {
            cnt = 1;
            x = l;
        }
    }
    cout << x << " " << cnt;
}

void solve2() { //Problem B
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, K;
    cin >> n >> K;
    vector<int> k(K);
    for (int i = 0; i < K; i++) {
        cin >> k[i];
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = i + 1;
    }
    //----------
    int lead = 0;
    for (int i = 0; i < K; i++) {
        int rotate = k[i];

        int del = (lead + rotate) % c.size();
        cout << c[del] << " ";
        cout.flush();

        int x;
        if (del == c.size() - 1) {
            x = c[0];
        }
        else {
            x = c[del + 1];
        }

        c.erase(c.begin() + del);

        for (int i1 = 0; i1 < c.size(); i1++) {
            if (c[i1] == x) {
                lead = i1;
                break;
            }
        }
    }
}

string v;

bool try_erase(const string& s) {
    v = s;

    int sum = 0;
    for (auto& c : v) {
        sum += c - '0';
    }

    sum %= 3;
    if (sum == 0) {
        return true;
    }

    for (int i = 1; i < s.size(); i++) {
        if ((s[i] - '0') % 3 == sum) {
            v.erase(i, 1);
            return true;
        }
    }

    vector<int> pos;

    int r = 3 - sum;
    for (int i = 1; i < s.size(); i++) {
        if ((s[i] - '0') % 3 == r) {
            pos.push_back(i);
        }
    }

    if (pos.size() > 1) {
        v.erase(pos[1], 1);
        v.erase(pos[0], 1);
        return true;
    }

    return false;
}

void solve3() { //Problem C
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    //----------
    int sum = 0;
    for (auto& i : s) {
        sum += i - '0';
    }

    if (sum % 3 == 0) {
        cout << s;
        return;
    }

    string ans;

    bool is_null_exist = false;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '0') {
            if (try_erase(s.substr(i))) {
                cnt++;
                if (cnt > 3) {
                    break;
                }
                if (v.size() > ans.size()) {
                    ans = v;
                }
            }
        }
        else {
            is_null_exist = true;
        }
    }

    if (ans.empty()) {
        if (is_null_exist) {
            cout << '0';
        }
        else {
            cout << -1;
        }
    }
    else {
        cout << ans;
    }
}

void solve4() { //Problem D
    ull n, q;
    cin >> n >> q;

    for (int i = 0; i < q; i++) {
        ull u;
        string s;
        cin >> u >> s;
        ull ans = u;
        for (auto c : s) {
            bitset<64> num2(ans);
            int k = 0;
            int j = 0;
            while (num2[j] != 1) {
                j++;
                k++;
            }

            if (c == 'L') {
                if (k == 0) {
                    continue;
                }
                else {
                    ull m = 1ull << (k - 1);
                    ans -= m;
                }
            }
            else if (c == 'R') {
                if (k == 0) {
                    continue;
                }
                else {
                    ull m = 1ull << (k - 1);
                    ans += m;
                }
            }
            else {
                ull m = 1ull << k;
                ull div1 = 1ull << (k + 1);
                ull div2 = 1ull << (k + 2);
                ull ans1 = ans + m;
                if (ans1 % div1 == 0 && ans1 % div2 != 0) {
                    if (ans1 <= n) {
                        ans = ans1;
                    }
                    else {
                        continue;
                    }
                }
                else {
                    ans -= m;
                }
            }
        }
        cout << ans << endl;
    }
}

int main() {
    //solve1();
    //solve2();
    //solve3();
    //solve4();
    return 0;
}