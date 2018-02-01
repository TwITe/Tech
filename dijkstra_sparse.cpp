#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

vector<vector<int>> g;
unordered_map<int, unordered_map<int, int>> w;
vector<int> dist, p;

const int INF = 2009000999;

void dijkstra(int start, int n) {
    dist[start] = 0;
    set<pair<int, int>> q;
    q.insert(make_pair(dist[start], start));

    while (!q.empty()) {
        if (q.begin()->first == INF) {
            break;
        }
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto u : g[v]) {
            int to = u, len = w[v][u];

            if (dist[v] + len < dist[to]) {
                q.erase(make_pair(dist[to], to));
                dist[to] = dist[v] + len;
                p[to] = v;
                q.insert(make_pair(dist[to], to));
            }
        }
    }
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s;
    cin >> n >> m >> s;
    g.resize(n);
    dist.resize(n, INF);
    p.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(b);
        g[b].push_back(a);
        w[a][b] = c;
        w[b][a] = c;
    }

    dijkstra(s, n);

    for (int i = 0; i < dist.size(); i++) {
        cout << "Minimal path to current node " << i << " is: " << dist[i] << endl;
        vector<int> path;
        for (int v = i; v != s; v = p[v])
            path.push_back(v);
        path.push_back(s);
        reverse(path.begin(), path.end());

        cout << "Path is: ";
        for (auto u : path) {
            cout << u << " -> ";
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}