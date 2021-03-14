#include <iostream>
#include <set>
#include <vector>
using namespace std;

#define MAX 100

set<int> s[MAX];

void similarity(set<int> &x, set<int> &y) {
    int all = 0, both = 0;
    set<int>::iterator m, n;
    m = x.begin();
    n = y.begin();
    while (m != x.end() && n != y.end()) {
        if (*m < *n) {
            m ++;
        } else if (*m > *n) {
            n ++;
        } else {
            both += 1;
            m ++;
            n ++;
        }
        all += 1;
    }
    while (m != x.end()) {
        m ++;
        all += 1;
    }
    while (n != y.end()) {
        n ++;
        all += 1;
    }
    printf("%.1f%%\n", 1.0 * both / all * 100.0);
}

int main()
{
    int n, m, x, y;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> m;
        for (int j = 0; j < m; j ++) {
            cin >> x;
            s[i].insert(x);
        }
    }
    cin >> m;
    for (int i = 0; i < m; i ++) {
        cin >> x >> y;
        similarity(s[x - 1], s[y - 1]);
    }
    return 0;
}