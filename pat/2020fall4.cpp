// 24/30 有两个点超时，感觉算法有待优化，想了半天还是不知道怎么优化
#include <iostream>
#include <vector>
using namespace std;
#define MAX 1001
#define INF 99999999
int g[MAX][MAX] = {0}, s[MAX][MAX] = {0}, d[MAX][MAX] = {0}, degree[MAX] = {0};
int n, m, k;

bool consistent() {
    int deg[MAX], count = 0, visit[MAX] = {0};
    for (int i = 0; i < n; i ++) {
        deg[i] = degree[i];
        visit[i] = 0;
    }
    while (count != n) {
        int found = -1;
        for (int i = 0; i < n; i ++) {
            if (deg[i] == 0 && visit[i] == 0) {
                found = i;
                break;
            }
        }
        if (found == -1) {
            return false;
        }
        visit[found] = 1;
        for (int i = 0; i < n; i ++) {
            if (visit[i] == 0 && g[found][i] == 1) {
                deg[i] -= 1;
            }
        }
        count += 1;
    }
    return true;
}

void min_path(int src, int des, vector<int> &res, int &sum, int &sumd) {
    int visit[MAX] = {0}, mark[MAX], getd[MAX] = {0}, pre[MAX];
    for (int i = 0; i < n; i ++) {
        mark[i] = INF;
        pre[i] = -1;
    }
    mark[src] = 0;
    for (;;) {
        int u = -1, minm = INF;
        for (int i = 0; i < n; i ++) {
            if (mark[i] < minm && visit[i] == 0) {
                minm = mark[i];
                u = i;
            }
        }
        if (u == -1) {
            break;
        }
        visit[u] = 1;
        for (int v = 0; v < n; v ++) {
            if (visit[v] == 0) {
                if (mark[v] > mark[u] + s[u][v]) {
                    mark[v] = mark[u] + s[u][v];
                    pre[v] = u;
                    getd[v] = getd[u] + d[u][v];
                } else if (mark[v] == mark[u] + s[u][v] && getd[v] < getd[u] + d[u][v]) {
                    pre[v] = u;
                    getd[v] = getd[u] + d[u][v];
                }
            }
        }
    }
    sum = mark[des];
    sumd = getd[des];
    int p = des;
    while (p != -1) {
        res.push_back(p);
        p = pre[p];
    }
}

int main()
{
    int u, v, w, x;
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (i != j) {
                s[i][j] = INF;
            }
        }
    }
    for (int i = 0; i < m; i ++ ) {
        cin >> u >> v >> w >> x;
        g[u][v] = 1;
        s[u][v] = w;
        d[u][v] = x;
        degree[v] += 1;
    }
    vector<int> src;
    for (int i = 0; i < n; i ++) {
        if (degree[i] == 0) {
            src.push_back(i);
        }
    }
    bool is = consistent();
    if (is) {
        cout << "Okay." << endl;
    } else {
        cout << "Impossible." << endl;
    }
    cin >> k;
    for (int i = 0; i < k; i ++) {
        cin >> x;
        if (degree[x] == 0) {
            printf("You may take test %d directly.\n", x);
        } else if (!is) {
            printf("Error.\n");
        } else {
            vector<vector<int>> res;
            int minsum = INF, mind = INF;
            for (int j = 0; j < src.size(); j ++) {
                vector<int> path;
                int sum = INF, sumd = INF;
                min_path(src[j], x, path, sum, sumd);
                if (sum < minsum || (sum == minsum && sumd > mind)) {
                    minsum = sum;
                    mind = sumd;
                    res.push_back(path);
                    break;
                }
            }
            int len = res.size() - 1;
            for (int j = res[len].size() - 1; j >= 0; j --) {
                printf("%d", res[len][j]);
                if (j != 0) {
                    printf("->");
                }
            }
            printf("\n");
        }
    }
    return 0;
}