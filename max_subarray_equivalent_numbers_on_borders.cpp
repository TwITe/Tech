#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll MAX = LONG_LONG_MAX;

struct min_sum_struct { // структура только для минимальной суммы элемента
    ll min_sum = MAX;
    int l; // левая граница
};

struct sum_struct { // структура для сумм на отрезках
    ll sum = -MAX;
    int r; // левая граница
    int l; // правая граница
};

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    ll sum[n + 1]; // частичные суммы
    ll max_element = -MAX;
    int max_elem_pos; // позиция максимального элемента
    //------

    sum[0] = 0;
    map<ll, min_sum_struct> min_sums; // тут хранится минимальная сумма
    map<ll, sum_struct> sums; // тут хранится максимальная суммы на отрезке

    for (int i = 0; i < n; i++) {
        cin >> v[i];

        sum[i + 1] = sum[i] + v[i];

        if (v[i] > max_element) {
            max_element = v[i];
            max_elem_pos = i;
        }

        if (min_sums.find(v[i]) != min_sums.end()) { // если минимальная сумма уже есть, и снова встретился тот же элемент
            //  то посчитаем сумму на данном отрезке (текущий индекс - индекс минимальной суммы)
            ll current_sum = sum[i + 1] - min_sums[v[i]].min_sum;
            if (current_sum > sums[v[i]].sum) {
                sums[v[i]].sum = current_sum;
                sums[v[i]].r = i;
                sums[v[i]].l = min_sums[v[i]].l;
            }
        }

        if (sum[i] < min_sums[v[i]].min_sum) { // устанавливаем минимальную встретившуюся сумму
            min_sums[v[i]].min_sum = sum[i];
            min_sums[v[i]].l = i;
        }
    }

    ll answer = -MAX;
    int answer_left_pos, answer_right_pos; // границы искомого отрезка
    for (auto it = sums.begin(); it != sums.end(); it++) { // будем проходить по мапе, и искать наибольшую сумму на отрезках
        // также, если элемент не встречался во 2-й раз, то его в мапе не будет,соответсвенно их рассматривать даже не будем
        ll current_sum = it->second.sum;

        if (current_sum > answer) {
            answer = current_sum;
            answer_right_pos = it->second.r;
            answer_left_pos = it->second.l;
        }
    }

    if (answer >= max_element) {
        cout << answer << endl << answer_left_pos + 1 << " " << answer_right_pos + 1;
    }
    else { // если наибольшая сумма на каком-то из отрезков оказалась меньше единичного числа, то выводим максимальное число              // и его позиции
        cout << max_element << endl << max_elem_pos + 1 << " " << max_elem_pos + 1;
    }
}

int main() {
    solve();
    return 0;
}
