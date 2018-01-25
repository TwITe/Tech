#include <bits/stdc++.h>
using namespace std;

vector<bool> vis;
vector<vector<int>> g;

void bfs(int start) {
    vis[start] = true;
    queue<int> q;
    q.(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

void solve() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;

        vis.clear();
        g.clear();
        vis.resize(n * m);
        g.resize(n * m);

        //preprocessing
        int arr[n][m];
        for (int i = 0; i < n; i++) {
            for (int i1 = 0; i1 < m; i1++) {
                arr[i][i1] = m * i + i1;
            }
        }

        char v[n][m];

        for (int i = 0; i < n; i++) {
            for (int i1 = 0; i1 < m; i1++) {
                cin >> v[i][i1];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int i1 = 0; i1 < m; i1++) {
                if (v[i][i1] == 'X') {
                    i - 1 >= 0 ? v[i - 1][i1] == 'X' ? g[arr[i][i1]].push_back(arr[i - 1][i1]) : (void) 0 : (void) 0;
                    i + 1 < n ? v[i + 1][i1] == 'X' ? g[arr[i][i1]].push_back(arr[i + 1][i1]) : (void) 0 : (void) 0;
                    i1 - 1 >= 0 ? v[i][i1 - 1] == 'X' ? g[arr[i][i1]].push_back(arr[i][i1 - 1]) : (void) 0 : (void) 0;
                    i1 + 1 < m ? v[i][i1 + 1] == 'X' ? g[arr[i][i1]].push_back(arr[i][i1 + 1]) : (void) 0 : (void) 0;
                }
            }
        }

        int cnt = 0;

        for (int i = 0; i < n * m; i++) {
            if (!vis[i] && v[i / m][i % m] == 'X') {
                cnt++;
                bfs(i);
            }
        }

        cout << cnt << endl;
    }
}

int main() {
    solve();
    return 0;
}