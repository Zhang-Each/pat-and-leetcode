#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct p {
    int v, t, all;
    string id;
    p(string x, int y, int z) {
        id = x;
        v = y;
        t = z;
        all = y + z;
    }
};

vector<p> a[4];

bool cmp(p &a, p &b) {
    if (a.all != b.all) {
        return a.all > b.all;
    }
    return a.v == b.v ? a.id < b.id : a.v > b.v;
}

int main()
{
    int n, l, h, v, t;
    string id;
    cin >> n >> l >> h;
    for (int i = 0; i < n; i ++) {
        cin >> id >> v >> t;
        if (v < l || t < l) {
            continue;
        } else {
            p temp(id, v, t);
            if (v >= h && t >= h) {
                a[0].push_back(temp);
            } else if (v >= h && t < h) {
                a[1].push_back(temp);
            } else if (v < h && v >= t) {
                a[2].push_back(temp);
            } else {
                a[3].push_back(temp);
            }
        }
    }
    int total = 0;
    for (int i = 0; i < 4; i ++) {
        total += a[i].size();
        sort(a[i].begin(), a[i].end(), cmp);
    }
    printf("%d\n", total);
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < a[i].size(); j ++) {
            printf("%s %d %d\n", a[i][j].id.c_str(), a[i][j].v, a[i][j].t);
        }
    }
    return 0;
}