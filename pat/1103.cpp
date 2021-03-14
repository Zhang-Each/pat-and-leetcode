#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int n, k, p;
vector<vector<int>> res;

int power(int n, int e) {
    int res = 1;
    for (int i = 0; i < e; i ++) {
        res *= n;
    }
    return res;
}

int total(vector<int> x) {
    int res = 0;
    for (int i = 0; i < x.size(); i ++) {
        res += x[i];
    }
    return res;
}

bool cmp(vector<int> &x, vector<int> &y) {
    if (total(x) > total(y)) {
        return true;
    } else if (total(x) == total(y)) {
        for (int i = 0; i < min(x.size(), y.size()); i ++) {
            if (x[i] != y[i]) {
                return x[i] > y[i];
            }
        }
        return x.size() > y.size();
    }
    return false;
}

void search(vector<int> &temp, int sum) {
    if (sum == n && temp.size() == k) {
        if (res.size() == 0) {
            res.push_back(temp);
        } else if (cmp(temp, res[0])) {
            res.pop_back();
            res.push_back(temp);
        }
        return;
    } else if (sum < n && temp.size() < k) {
        int start;
        if (temp.size() == 0) {
            start = (int)pow(n, 1.0 / p) + 1;
        } else {
            start = temp[temp.size() - 1];
        }
        for (int i = start; i >= 1; i --) {
            if (sum + power(i, p) <= n) {
                temp.push_back(i);
                search(temp, sum + power(i, p));
                temp.pop_back();
            }
        }
    }
}

int main()
{
    cin >> n >> k >> p;
    vector<int> temp;
    search(temp, 0);
    if (res.size() == 0 ) {
        cout << "Impossible" << endl;
        return 0;
    }
    printf("%d =", n);
    for (int i = 0; i < k; i ++) {
        printf(" %d^%d", res[0][i], p);
        if (i != k - 1) {
            printf(" +");
        }
    }
    return 0;
}