#include <iostream>
using namespace std;

#define MAX 1001
int g[MAX][MAX] = {0};
int visit[MAX] = {0};
int n, m, k;

// 要求的其实就是强连通分量的数目

void dfs(int index) {
    visit[index] = 1;
    for (int i = 1; i <= n; i ++) {
        if (g[index][i] == 1 && visit[i] == 0) {
            dfs(i);
        }
    }
}

int main()
{
    int a, b;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i ++) {
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }
    int x;
    for (int i = 0; i < k; i ++) {
        cin >> x;
        for (int j = 1; j <= n; j++ ) {
            visit[j] = 0;
        }
        visit[x] = 1;
        int count = 0;
        for (int j = 1; j <= n; j ++) {
            if (visit[j] == 0) {
                dfs(j);
                count += 1;
            }
        }
        cout << count - 1 << endl;
    }
    return 0;
}