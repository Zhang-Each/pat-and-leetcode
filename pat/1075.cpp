#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define MAX 10001
#define K 6

struct pat {
    int id;
    int a[K] = {-1};
    int total = 0;
    int full = 0;
};

bool cmp(pat &x, pat &y) {
    if (x.total > y.total) {
        return true;
    } else if (x.total == y.total) {
        if (x.full > y.full) {
            return true;
        } else if (x.full == y.full) {
            return x.id < y.id;
        }
    }
    return false;
}

pat res[MAX];

int main()
{
    int n, m, k, id, s, name;
    cin >> n >> k >> m;
    int scores[6];
    for (int i = 1; i <= k; i ++) {
        scanf("%d", &scores[i]);
    }
    for (int i = 1; i <= n; i ++) {
        res[i].id = i;
        for (int j = 1; j <= k; j ++) {
            res[i].a[j] = -100;
        }
    }
    for (int i = 0; i < m; i ++) {
        cin >> name >> id >> s;
        if (s > res[name].a[id]) {
            res[name].a[id] = s;
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= k; j ++) {
            if (res[i].a[j] != -100) {
                res[i].total += res[i].a[j];
            }
            if (res[i].a[j] == scores[j]) {
                res[i].full += 1;
            }
        }
    }
    sort(res + 1, res + n + 1, cmp);
    int rank = 1;
    for (int i = 1; i <= n; i ++) {
        if (res[i].total == 0) {
            break;
        }
        if (i >= 2 && res[i].total != res[i - 1].total) {
            rank = i;
        }
        printf("%d %05d %d", rank, res[i].id, res[i].total);
        for (int j = 1; j <= k; j ++) {
            cout << " ";
            if (res[i].a[j] == -100) {
                cout << "-";
            } else {
                cout << (res[i].a[j] > 0 ? res[i].a[j] : 0);
            }
        }
        cout << endl;
    }
    return 0;
}