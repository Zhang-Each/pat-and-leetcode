// 并查集和排序题的缝合题，写起来比较麻烦
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define MAX 10001
map<int, int> label, r_label;
map<int, int> estate, area;
int _count = 1;
int fam[MAX] = {0};

struct family {
    int cnt, id;
    double res1, res2;
    family (int w, int x, double y, double z) {
        id = w;
        cnt = x;
        res1 = y / x;
        res2 = z / x;
    }
};

bool cmp(family &x, family &y) {
    if (x.res2 != y.res2) {
        return x.res2 > y.res2;
    }
    return x.id < y.id;
}

void add(int x) {
    if (label[x] == 0) {
        label[x] = _count;
        r_label[_count] = x;
        _count += 1;
    }
}

int find_root(int x) {
    if (fam[x] == x) {
        return x;
    }
    return fam[x] = find_root(fam[x]);
}

void add_root(int x, int y) {
    int xx = find_root(x), yy = find_root(y);
    if (xx < yy) {
        fam[yy] = xx;
    } else {
        fam[xx] = yy;
    }
}

int main()
{
    int n, s, f, m, k;
    cin >> n;
    for (int i = 0; i < MAX; i ++) {
        fam[i] = i;
    }
    for (int i = 0; i < n; i ++) {
        cin >> s >> f >> m >> k;
        add(s);
        if (f != -1) {
            add(f);
            add_root(label[s], label[f]);
        }
        if (m != -1) {
            add(m);
            add_root(label[s], label[m]);
        }
        int son, e, a;
        for (int j = 0; j < k; j ++) {
            cin >> son;
            add(son);
            add_root(label[s], label[son]);
        }
        cin >> e >> a;
        estate[s] = e;
        area[s] = a;
    }
    set<int> num;
    for (int i = 1; i < _count; i ++) {
        find_root(i);
        num.insert(fam[i]);
    }
    cout << num.size() << endl;
    vector<family> res;
    for (auto it = num.begin(); it != num.end(); it ++) {
        double res1 = 0, res2 = 0;
        int cnt = 0, minid = 10000;
        for (int i = 1; i < _count; i ++) {
            if (fam[i] == *it) {
                int id = r_label[i];
                res1 += estate[id];
                res2 += area[id];
                cnt ++;
                if (id < minid) {
                    minid = id;
                }
            }
        }
        family temp(minid, cnt, res1, res2);
        res.push_back(temp);
    }
    sort(res.begin(), res.end(), cmp);
    for (int i = 0; i < res.size(); i ++) {
        printf("%04d %d %.3f %.3f\n", res[i].id, res[i].cnt, res[i].res1, res[i].res2);
    }
    return 0;
}