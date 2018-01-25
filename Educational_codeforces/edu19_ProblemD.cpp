#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

vector<int> val;
vector<pair<int, int>> g;
unordered_set<ll> finded;

void dfs(int u, int min_val, int max_val, char d = 0) {
    if (d == 'L') {
        if (val[u] < min_val && val[u] > max_val) {
            finded.insert(val[u]);
        }
    }
    if (d == 'R') {
        if (val[u] < min_val && val[u] >= max_val) {
            finded.insert(val[u]);
        }
    }

    if (g[u].first != -1) {
        dfs(g[u].first, min(min_val, val[u]), max_val, 'L');
    }
    if (g[u].second != -1) {
        dfs(g[u].second, min_val, max(max_val, val[u]), 'R');
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    val.resize(n);
    g.resize(n);
    vector<bool> exist(n);

    int max_val = 0;

    for (int i = 0; i < n; i++) {
        int v, l, r;
        cin >> v >> l >> r;
        if (l != -1) {
            --l;
            exist[l] = true;
        }
        if (r != -1) {
            --r;
            exist[r] = true;
        }

        max_val = max(max_val, v);

        val[i] = v;
        g[i].first = l;
        g[i].second = r;
    }

    int root;
    for (int i = 0; i < n; i++) {
        if (!exist[i]) {
            root = i;
            break;
        }
    }

    if (g[root].first != -1) {
        int m = g[root].second;
        g[root].second = -1;
        dfs(root, val[root], -1);
        g[root].second = m;
    }

    if (g[root].second != -1) {
        g[root].first = -1;
        dfs(root, (int)1e9 + 1, -1);
    }

    finded.insert(val[root]);

    int ans = 0;
    for (int i = 0; i < val.size(); i++) {
        if (finded.find(val[i]) == finded.end()) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}