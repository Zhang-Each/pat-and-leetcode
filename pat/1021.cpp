// 好题，先用dfs判断连通分量的个数，然后遍历两次获取深度最大的节点
#include <iostream>
#include <set>
using namespace std;

#define MAX 10001
int g[MAX][MAX] = {0};
int visit[MAX] = {0}, n, maxh = 0;
set<int> res;

void dfs(int index, int flag) {
    visit[index] = flag;
    for (int i = 1; i <= n; i ++) {
        if (visit[i] == 0 && g[index][i] == 1) {
            dfs(i, flag);
        }
    }
}

void find(int i, int h) {
    maxh = max(maxh, h);
    visit[i] = h;
    for (int j = 1; j <= n; j ++) {
        if (visit[j] == 0 && g[i][j] == 1) {
            find(j, h + 1);
        }
    }
}

int main()
{
    int a, b, count = 0, select;
    cin >> n;
    for (int i = 0; i < n - 1; i ++) {
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }
    for (int i = 1; i <= n; i ++) {
        if (visit[i] == 0) {
            dfs(i, ++count);
        }
    }
    if (count != 1) {
        printf("Error: %d components\n", count);
        return 0;
    }
    fill(visit, visit + MAX, 0);
    find(1, 1);
    for (int i = 1; i <= n; i ++) {
        if (visit[i] == maxh) {
            res.insert(i);
            select = i;
        }
    }
    fill(visit, visit + MAX, 0);
    maxh = 0;
    find(select, 1);
    for (int i = 1; i <= n; i ++) {
        if (visit[i] == maxh) {
            res.insert(i);
            select = i;
        }
    }
    for (set<int>::iterator it = res.begin(); it != res.end(); it ++) {
        cout << *it << endl;
    }
    return 0;
}