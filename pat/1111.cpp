#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

#define INF 9999999
#define MAX 1000
int g[MAX][MAX] = {0}, s[MAX][MAX] = {0}, n, m;
int visit[MAX] = {0}, dist[MAX], tim[MAX], pre1[MAX], pre2[MAX], sum[MAX], num[MAX];

bool same(vector<int> x, vector<int> y) {
    if (x.size() != y.size()) {
        return false;
    }
    for (int i = 0; i < x.size(); i ++) {
        if (x[i] != y[i]) {
            return false;
        }
    }
    return true;
}
void show(vector<int> s) {
    for (int i = s.size() - 1; i >= 0; i --) {
        printf(" %d", s[i]);
        if (i != 0) {
            printf(" ->");
        }
    }
    printf("\n");
}

int main()
{
    cin >> n >> m;
    int u, v, f, l, t, src, des;
    vector<int> path1, path2;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            g[i][j] = INF;
            s[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i ++) {
        cin >> u >> v >> f >> l >> t;
        if (f == 0) {
            g[v][u] = l;
            s[v][u] = t;
        }
        g[u][v] = l;
        s[u][v] = t;
    }
    cin >> src >> des;
    for (int i = 0; i < n; i ++) {
        dist[i] = INF;
        tim[i] = INF;
        sum[i] = INF;
        num[i] = INF;
        pre1[i] = pre2[i] = -1;
    }
    dist[src] = 0;
    tim[src] = 0;
    num[src] = 0;
    sum[src] = 0;
    // 找最短距离
    for (; ; ) {
        int u = -1, mind = INF;
        for (int i = 0; i < n; i ++) {
            if (visit[i] == 0 && dist[i] < mind) {
                u = i;
                mind = dist[i];
            }
        }
        if (u == -1) {
            break;
        }
        visit[u] = 1;
        for (int v = 0; v < n; v ++ ) {
            if (visit[v] == 0 && g[u][v] != INF) {
                if (dist[v] > dist[u] + g[u][v]) {
                    dist[v] = dist[u] + g[u][v];
                    pre1[v] = u;
                    sum[v] = sum[u] + s[u][v];
                }
                else if (dist[v] == dist[u] + g[u][v] && sum[v] > sum[u] + s[u][v]) {
                    pre1[v] = u;
                    sum[v] = sum[u] + s[u][v];
                }
            } 
        }
    }
    int p = des;
    while (p != -1) {
        path1.push_back(p);
        p = pre1[p];
    }
    for (int i = 0; i < n; i ++) {
        visit[i] = 0;
    }
    // 最短时间
    for (; ; ) {
        int u = -1, mind = INF;
        for (int i = 0; i < n; i ++) {
            if (visit[i] == 0 && tim[i] < mind) {
                u = i;
                mind = tim[i];
            }
        }
        if (u == -1) {
            break;
        }
        visit[u] = 1;
        for (int v = 0; v < n; v ++ ) {
            if (visit[v] == 0 && s[u][v] != INF) {
                if (tim[v] > tim[u] + s[u][v]) {
                    tim[v] = tim[u] + s[u][v];
                    pre2[v] = u;
                    num[v] = num[u] + 1;
                }
                else if (tim[v] == tim[u] + s[u][v] && num[v] > num[u] + 1) {
                    pre2[v] = u;
                    num[v] = num[u] + 1;
                }
            } 
        }
    }
    p = des;
    while (p != -1) {
        path2.push_back(p);
        p = pre2[p];
    }
    if (same(path1, path2)) {
        printf("Distance = %d; Time = %d:", dist[des], tim[des]);
        show(path1);
    } else {
        printf("Distance = %d:", dist[des]);
        show(path1);
        printf("Time = %d:", tim[des]);
        show(path2);
    }
    
    return 0;
}