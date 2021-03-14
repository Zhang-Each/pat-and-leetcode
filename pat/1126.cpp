#include <iostream>
using namespace std;

#define MAX 1000
int deg[MAX] = {0};
int g[MAX][MAX] = {0};
int visit[MAX] = {0};

/**
 * 要注意题目中的是一个充分不必要条件，如果一个图的度数都是偶数，也要判断该图是否拥有完整的回路
 * 因此需要先dfs遍历一次
 */
void dfs(int index, int n) {
    visit[index] = 1;
    for (int i = 1; i <= n; i ++) {
        if (g[index][i] == 1 && visit[i] == 0) {
            dfs(i, n);
        }
    }
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        cin >> a >> b;
        deg[a] += 1;
        deg[b] += 1;
        g[a][b] = g[b][a] = 1;
    }
    int odd = 0;
    for (int i = 1; i <= n; i ++) {
        if (deg[i] % 2 == 1) {
            odd += 1;
        }
        if (i != 1) {
            cout << " ";
        }
        cout << deg[i];
    }
    cout << endl;
    dfs(1, n);
    for (int i = 1; i <= n; i ++) {
        if (visit[i] == 0) {
            cout << "Non-Eulerian" << endl;
            return 0;
        }
    }
    if (odd == 0) {
        cout << "Eulerian" << endl;
    } else if (odd == 2) {
        cout << "Semi-Eulerian" << endl;
    } else {
        cout << "Non-Eulerian" << endl;
    }
    return 0;
}