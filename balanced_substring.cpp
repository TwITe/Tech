// сбалансированная подстрока [cnt(0) == cnt(1))
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll MAX = LONG_LONG_MAX;
void solve2() { // сбалансированная подстрока [cnt(0) == cnt(1))
    int n;
    cin >> n;
    string s;
    cin >> s;
    map <int, int> a;
    int cnt0 = 0;
    int cnt1 = 0;
    a[0] = -1;
    int bal = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cnt1++;
        }
        else {
            cnt0++;
        }
        bal = cnt1 - cnt0;
        if (a.find(bal) != a.end()) {
            ans = max(ans, i - a[bal]);
        }
        else {
            a[bal] = i;
        }
    }
    cout << ans;
}

int main() {
    solve2();
    return 0;
}
