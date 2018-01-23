#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define INF (ll)(1e9 + 7)

vector<vector<ll>> dist;
vector<pair<ll, ll>> base;
vector<vector<ll>> used;
ll n, m;
ll k;
ll cnt = 0;
ll d;

vector<pair<ll, ll>> p;

bool dfs(ll i, ll j) {
    if (i < 0 || i > n - 1 || j < 0 || j > m - 1)
        return false;
    if (dist[i][j] < d) {
        return false;
    }
    if (j == m - 1) {
        return true;
    }
    used[i][j] = cnt;

    if (i != 0 && used[i - 1][j] != cnt) {
        bool tmp = dfs(i - 1, j);
        if (tmp) {
            p.emplace_back(make_pair(i - 1, j));
            return true;
        }
    }
    if (i != n - 1 && used[i + 1][j] != cnt) {
        bool tmp = dfs(i + 1, j);
        if (tmp) {
            p.emplace_back(make_pair(i + 1, j));
            return true;
        }
    }
    if (j != 0 && used[i][j - 1] != cnt) {
        bool tmp = dfs(i, j - 1);
        if (tmp) {
            p.emplace_back(make_pair(i, j - 1));
            return true;
        }
    }
    if (j != m - 1 && used[i][j + 1] != cnt) {
        bool tmp = dfs(i, j + 1);
        if (tmp) {
            p.emplace_back(make_pair(i, j + 1));
            return true;
        }
    }
    return false;
}

bool check(ll prob) {
    d = prob;
    cnt++;

    for (int i = 0; i < n; i++) {
        //if (used[i][0] != cnt) {
        p.clear();
        bool ans = dfs(i, 0);
        if (ans) {
            reverse(p.begin(), p.end());
            cout << endl << "The path is: ";
            for (auto i1 : p) {
                cout << i1.first << " " << i1.second << " -> ";
            }
            cout << endl;

            return true;
        }
        //}
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    dist.resize(n, vector<ll>(m, INF));
    used.resize(n, vector<ll>(m, 0));
    base.resize(k);

    for (int i = 0; i < base.size(); i++) {
        cin >> base[i].first >> base[i].second;
        base[i].first--;
        base[i].second--;
    }

    // Немного переделанный алгоритм Флойда-Уоршелла
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int b = 0; b < k; b++) {
                dist[i][j] = min(dist[i][j], abs(i - base[b].first) + abs(j - base[b].second));
            }
        }
    }

    for (int i = 0; i < dist.size(); i++) {
        for (int j = 0; j < dist[i].size(); j++) {
            cout << "Minimal path to the nearest pirate base from " << i << " to " << j << " is: " << dist[i][j] << endl;
        }
        cout << endl;
    }
    cout << endl;

    ll mid = 1;
    while (check(mid)) {
        mid++;
    }

    cout << endl << "The answer is: " << mid - 1;
    return 0;
}