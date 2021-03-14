#include <iostream>
#include <set>
using namespace std;

#define MAX 201

int graph[MAX][MAX] = {0};
int n;

bool isHamilton(int a[], int len, int n) {
    if (len != n + 1 || a[0] != a[len - 1]) {
        return false;
    }
    set<int> node;
    node.insert(a[0]);
    for (int i = 0; i < len - 1; i ++) {
        if (graph[a[i]][a[i + 1]] == 0) {
            return false;
        }
        node.insert(a[i + 1]);
    }
    if (node.size() != n) {
        return false;
    }
    return true;
}

int main()
{
    int m, l, x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    cin >> l;
    for (int i = 0; i < l; i ++) {
        int len;
        cin >> len;
        int *a = new int[len];
        for (int j = 0; j < len; j ++) {
            cin >> a[j];
        }
        if (isHamilton(a, len, n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}