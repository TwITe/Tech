#include <bits/stdc++.h>
using namespace std;
using ul = unsigned long;

//vector<ul> v;
ul k_pos{0};

bool bin_search(ul left, ul right, ul k, const vector<int>& v, ul mid = 0) {
    while (right - left > 0) {
        mid = (left + right) >> 1;

        if (k <= v[mid]) {
            right = mid;
        }
        else if (k > v[mid]) {
            left = mid + 1;
        }
    }
    if (v[right] == k) {
        k_pos = right;
        return true;
    }
    return false;
}

long solve(ul k, const vector<int>& v) {
    ul n;
    /*cin >> n >> k;*/
    //v.resize(n);
    ul division_pos{0};
    for (ul i = 0; i < v.size(); i++) {
        /*cin >> v[i];*/
        if (i > 0) {
            if (v[i] < v[i - 1]) {
                division_pos = i;
            }
        }
    }
    ul left = 0, right = division_pos - 1;
    if (bin_search(left, right, k, v)) {
        return k_pos;
    }
    left = division_pos, right = v.size() - 1;
    if (bin_search(left, right, k, v)) {
        return k_pos;
    }
    return -1;
}

//tests
bool test1() {
    ul n;
    cout << "Enter array size: ";
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = i;
    }
    ul pos, k, rotate_pos;
    cout << "Enter key: ";
    cin >> k;
    cout << "Enter rotate pos: ";
    cin >> rotate_pos;
    pos = k;
    rotate(v.begin(), v.begin() + rotate_pos, v.end());
    if (k < rotate_pos) {
        pos = n - rotate_pos + k;
    }
    else if (k > rotate_pos) {
        pos -= rotate_pos;
    }
    else {
        pos = 0;
    }
    assert(pos == solve(k, v));
    cout << endl << "Accepted";
    return true;
}

int main() {
    assert(test1());

    return 0;
}