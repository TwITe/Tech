#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void towers(int n, int from, int to, int free) {
    if (n != 0) {
        towers(n - 1, from, free, to);
        cout << from << " " << to << " ";
        towers(n - 1, free, to, from);
    }
}

void solve() {
    int n;
    cin >> n;
    towers(n, 1, 2, 3);
}

int main() {
    solve();
    return 0;
}