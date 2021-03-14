#include <iostream>
#include <vector>
using namespace std;

#define MAX 501
#define INF 9999999
int len[MAX][MAX], cost[MAX][MAX], dist[MAX], visit[MAX], pre[MAX], money[MAX] = {0};
int n, m, src, des;
vector<int> path;

int main()
{
    cin >> n >> m >> src >> des;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            len[i][j] = INF;
            cost[i][j] = INF;
        }
        len[i][i] = cost[i][i] = 0;
        dist[i] = INF;
        visit[i] = 0;
        pre[i] = -1;
        money[i] = 0;
    }
    int x, y, l, c;
    for (int i = 0; i < m; i ++) {
        cin >> x >> y >> l >> c;
        len[x][y] = len[y][x] = l;
        cost[x][y] = cost[y][x] = c;
    }

    dist[src] = 0;
    money[src] = 0;
    for (;;) {
        int u = -1, min = INF;
        for (int i = 0; i < n; i ++) {
            if (dist[i] < min && visit[i] == 0) {
                u = i;
                min = dist[i];
            }
        }
        if (u == -1) {
            break;
        }
        visit[u] = 1;
        for (int v = 0; v < n; v ++) {
            if (visit[v] == 0) {
                if (dist[v] > dist[u] + len[u][v]) {
                    dist[v] = dist[u] + len[u][v];
                    money[v] = money[u] + cost[u][v];
                    pre[v] = u;
                } else if (dist[v] == dist[u] + len[u][v]) {
                    if (money[v] > money[u] + cost[u][v]) {
                        money[v] = money[u] + cost[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
    
    int p = des;
    while (p != -1) {
        path.push_back(p);
        p = pre[p];
    }
    for (int i = path.size() - 1; i >= 0; i --) {
        cout << path[i] << " ";
    }
    cout << dist[des] << " " << money[des];
    return 0;
}