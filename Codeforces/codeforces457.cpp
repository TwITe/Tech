#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    ll ans = -1e6 - 1;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        double spart;
        if (modf(sqrt(a), &spart) != 0) {
            ans = max(ans, a);
        }
    }
    cout << ans;
}

int main() {
    solve();
    return 0;
}