#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

vector<vector<int>> g;
vector<char> color;
vector<int> path, cycle;
int cycle_start, cycle_end;

bool dfs1(int v) { // поиск цикла в графе, проверка на ацикличность
    color[v] = 1;
    for (auto u : g[v]) {
        int to = u;
        if (color[to] == 0) {
            path[to] = v;
            if (dfs1(to)) {
                return true;
            }
        }
        else if (color[to] == 1) {
            cycle_start = to;
            cycle_end = v;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

int main() {
    dfs1(0);
    return 0;
}