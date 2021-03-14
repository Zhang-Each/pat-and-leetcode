#include <iostream>
#include <map>
using namespace std;

#define MAX 201
int n, m, k;
int g[MAX][MAX] = {0};

bool isClique(int a[], int len) {
    for (int i = 0; i < len; i ++) {
        for (int j = i + 1; j < len; j ++) {
            if (g[a[i]][a[j]] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool isMaxClique(int a[], int len) {
    map<int, int> node;
    for (int i = 0; i < len; i ++) {
        node[a[i]] = 1;
    }
    for (int i = 1; i <= n; i ++) {
        if (node[i] == 0) {
            bool all_adjancent = true;
            for (int j = 0; j < len; j ++) {
                if (g[i][a[j]] == 0) {
                    all_adjancent = false;
                }
            }
            if (all_adjancent) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }
    cin >> k;
    for (int i = 0; i < k; i ++) {
        int len;
        cin >> len;
        int *a = new int[len];
        for (int j = 0; j < len; j ++) {
            cin >> a[j];
        }
        if (!isClique(a, len)) {
            cout << "Not a Clique" << endl;
        } else if (!isMaxClique(a, len)) {
            cout << "Not Maximal" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}
