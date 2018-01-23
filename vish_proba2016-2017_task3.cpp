#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() { // Problem C
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    //------------

    int fall = 0;
    vector<string> ans1, ans2;
    for (int i = 0; i < n; i++) {
        if (i == fall) {
            ans1.emplace_back(to_string(i + 1) + " " + "R");
        }
        fall = max(fall, i + v[i]);
    }
    fall = n - 1;

    for (int i = n - 1; i >= 0; i--) {
        if (i == fall) {
            ans2.emplace_back(to_string(i + 1) + " " + "L");
        }
        fall = min(fall, i - v[i]);
    }
    //------------

    if (ans1.size() < ans2.size()) {
        cout << ans1.size() << endl;
        for (const auto& i : ans1) {
            cout << i << endl;
        }
    }
    else {
        cout << ans2.size() << endl;
        for (const auto& i : ans2) {
            cout << i << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}