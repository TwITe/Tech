#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
unordered_map<int, unordered_map<int, int>> w;
vector<int> dist, p;
vector<bool> used;

const int INF = 1e5;

int ans = - 1;

void dijkstra(int start, int n) {
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && (v == -1 || dist[j] < dist[v])) {
                v = j;
            }
        }
        if (dist[v] == INF) {
            break;
        }
        used[v] = true;

        for (auto u : g[v]) {
            int to = u, len = w[v][u];
            if (dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
                p[to] = v;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, start, end;
    cin >> n >> start >> end;
    --start, --end;
    g.resize(n);
    dist.resize(n, INF);
    used.resize(n);
    p.resize(n);
    dist[start] = 0;
    for (int i = 0; i < n; i++) {
        for (int i1 = 0; i1 < n; i1++) {
            int a;
            cin >> a;
            if (a != -1) {
                g[i].push_back(i1);
                w[i][i1] = a;
            }
        }
    }

    dijkstra(start, n);
    ans = dist[end];
    if (ans == INF) {
        ans = -1;
    }

//    vector<int> path;
//    for (int v = end; v != start; v = p[v]) {
//        path.push_back(v);
//    }
//    path.push_back(start);
//    reverse(path.begin(), path.end());
//
//    cout << endl << "The path is: ";
//    for (auto i : path) {
//        cout << i << " ";
//    }
    cout << /*endl << "The answer is: " << */ ans;
}