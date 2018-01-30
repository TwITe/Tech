//template<typename T> T sqr(const T &x) {
//    return x * x;
//}
//long long gcd(long long a, long long b) {
//    if (b == 0) {
//        return a;
//    }
//    return gcd(b, a % b);
//}
//
//long long lcm(long long a, long long b) {
//	return a / gcd(a, b) * b;
//}
//

//int gcd (int a, int b, int& x, int& y) { // Расширенный алгоритм Евклида
//    // с помощью него можно решать диофантовы уравнения
//    if (a == 0) {
//        x = 0;
//        y = 1;
//        return b;
//    }
//    int x1, y1;
//    int d = gcd(b % a, a, x1, y1);
//    x = y1 - (b / a) * x1;
//    y = x1;
//    return d;
//}

//bool find_any_solution (int a, int b, int c, int& x0, int& y0, int& g) { //Решение диофантовых уравнений
//    g = gcd(abs(a), abs(b), x0, y0);
//    if (c % g != 0)
//        return false;
//    x0 *= c / g;
//    y0 *= c / g;
//    if (a < 0) x0 *= -1;
//    if (b < 0) y0 *= -1;
//    return true;
//}

//void dfs1(int node, int prev, int c) {
//    int cnt = 0;
//    for (int i: v[node]) {
//        if (i == prev) {
//            continue;
//        }
//        while (cnt == color[node] || cnt == c) {
//            ++cnt;
//        }
//        r = max(r, cnt + 1);
//        color[i] = cnt;
//        dfs(i, node, color[node]);
//        ++cnt;
//    }
//}
//bool used[MAXN] {false};
//void dfs(int v) {
//    used[v] = true;
//    for (auto u : edges[v])
//        if (!vis[u]) {
//            dfs1(u);
//        }
//}
//void fill_fraph{
//        for (int i = 0; i < n - 1; i++) {
//            int a, b;
//            cin >> a >> b;
//            a--, b--;
//            v[a].push_back(b);
//            v[b].push_back(a);
//        }
//        dfs(0);
//}
//void bin_search () {
//    while (l != r) {
//        int md = (l + r) / 2;
//        int q = 0;
//        if (q) {
//            r = md; // если больше, меняем верхнюю границу
//        }
//        else {
//            l = md + 1; //если меньше искомого, меняем нижнюю границу
//        }
//    }
//}
//void bin_s_primer() {
//    while (l != r) {
//        int md = (l + r) / 2;
//        int v = a[md].second;
//        int q = 0;
//        bool ok = true;
//        for (int i = 0; i < k - 1; i++) {
//            int d = b[i + 1] - b[i];
//            if (d > v) {
//                ok = false;
//                break;
//            }
//            q += max(d, d * 2 - (v - d));
//        }
//        if (ok && q <= t) {
//            r = md;
//        }
//        else {
//            l = md + 1;
//        }
//    }
//}
//
//void dfs (int node) { // компоненты связности
//    used[node] = true;
//    comp.push_back(node);
//    for (int to : v[node]) {
//        if (!used[to]) {
//            dfs(to);
//        }
//    }
//}
//
//void comp_find() {
//    for (int i = 0; i < n; i++) {
//        if (!v[i].empty()) {
//            if (!used[i]) {
//                comp.clear();
//                dfs(i);
//                unsigned long long min = c[comp[0]];
//                for (auto j : comp) {
//                    if (c[j] < min) {
//                        min = c[j];
//                    }
//                }
//                ans += min;
//            }
//        }
//    }
//}
// M Coloring Problem (Backtracking)
//bool used[MAXN] {false};
//int color[MAXN];
//vector <vector <int>> v;
//
//bool isSafe(int node, int c) {
//    for (int i : v[node])
//        if (c == color[i]) {
//            return false;
//        }
//    return true;
//}
//
//bool graph_coloring(int n, int m, int node) {
//    if (node == n) {
//        return true;
//    }
//    for (int c = 1; c <= m; c++) {
//        if (isSafe(node, c)) {
//            color[node] = c;
//            if (graph_coloring(n, m, node + 1)) {
//                return true;
//            }
//            color[node] = 0;
//        }
//    }
//    return false;
//}

//----------------------
//long num multiplicaion

//read long num
//for (int i = (int) s.length(); i > 0; i--) {
//a.push_back(atoi(s.substr(i - 1, 1).c_str()));
//}

//multiplication
//int carry = 0;
//for (size_t i = 0; i < a.size() || carry; i++) {
//if (i == a.size()) {
//a.push_back(0);
//}
//long long cur = carry + a[i] * b;
//a[i] = int(cur % base);
//carry = int(cur / base);
//}

//while (a.size() > 1 && a.back() == 0) {
//a.pop_back();
//}
//----------------------