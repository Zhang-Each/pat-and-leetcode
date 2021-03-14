// 这题没做出来，求出最短路径之后最后的显示路径工作出问题了，就先搁置了
#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define MAX 101
#define INF 999999
int g[MAX][MAX] = {0};
map<int, int> s, label1, label2;
int cnt = 1;

void add(int x) {
    if (label1[x] == 0) {
        label1[x] = cnt;
        label2[cnt] = x;
        cnt += 1;
    }
}

int main()
{
    int n, m, k, src, des;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> k;
        int *a = new int[k];
        for (int j = 0; j < k; j ++) {
            cin >> a[j];
            add(a[j]);
            s[label1[a[j]]] = i;
        }
        for (int j = 1; j < k; j ++) {
            g[label1[a[j]]][label1[a[j - 1]]] = g[label1[a[j - 1]]][label1[a[j]]] = 1;
        }
    }
    cin >> m;
    while (m--) {
        cin >> src >> des;
        int visit[MAX], dist[MAX], num[MAX], pre[MAX];
        for (int i = 1; i < cnt; i ++) {
            dist[i] = INF;
            num[i] = INF;
            visit[i] = 0;
            pre[i] = -1;
        }
        num[label1[src]] = 0;
        dist[label1[src]] = 0;
        for (; ;) {
            int u = -1, mind = INF;
            for (int i = 1; i < cnt; i ++) {
                if (dist[i] < mind && visit[i] == 0) {
                    u = i;
                    mind = dist[i];
                }
            }
            if (u == -1) {
                break;
            }
            visit[u] = 1;
            
            for (int v = 1; v < cnt; v ++) {
                if (visit[v] == 0 && g[u][v] == 1) {
                    if (dist[v] > dist[u] + g[u][v]) {
                        dist[v] = dist[u] + g[u][v];
                        num[v] = num[u] + 1;
                        pre[v] = u;
                    } else if (dist[v] == dist[u] + g[u][v] && num[v] > num[u] + 1) {
                        num[v] = num[u] + 1;
                        pre[v] = u;
                    }
                } 
            }
        }
        vector<int> path;
        int p = label1[des];
        while (p != -1) {
            path.push_back(p);
            p = pre[p];
        }
        int first = s[path[path.size() - 1]];
        for (int i = path.size() - 1; i >= 0; i --) {
            if (s[path[i]] != first) {
                printf("Take Line#%d from %04d to %04d.\n", first, label2[path[first]], label2[path[i + 1]]);
                first = s[path[i]];
            }
        }
    }
    return 0;
}