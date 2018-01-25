#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

bool used[];
vector<vector<int>> g;

//https://habrahabr.ru/post/259295/
//Реализация обхода в ширину

void bfs(int u) {
    used[u] = true;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < (int) g[u].size(); i++) {
            int v = g[u][i];
            if (!used[v]) {
                used[v] = true;
                q.push(v);
            }
        }
    }
}

//Поиск путей и расстояний
void bfs_search_dist_and_path(int u) {
    used[u] = true;
    path[u] = u;
    dist[u] = 0;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < (int) g[u].size(); i++) {
            int v = g[u][i];
            if (!used[v]) {
                used[v] = true;
                path[v] = u;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

//Кратчайшие пути от вершины
const int INF = 1e+9;

vector< pair<int, int> > g[LIM]; // В g[u] лежит список пар: (длина пути между вершиной u и v, вершина v)

void shortcut(int u) {
    fill(dist, dist + n, INF);
    dist[u] = 0;
    p[u] = u;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < (int) g[u].size(); i++) {
            int v = g[u][i].second, len = g[u][i].first;
            if (dist[v] > dist[u] + len) {
                p[v] = u;
                dist[v] = dist[u] + len;
                q.push(v);
            }
        }
    }
}

int main() {
    //bfs(0);
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
    return 0;
}