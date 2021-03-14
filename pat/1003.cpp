#include <iostream>
using namespace std;

#define MAX 501
#define INF 12345678
int team[MAX] = {0};
int city[MAX][MAX] = {0};

int main()
{
    int n, m, src, des;
    cin >> n >> m >> src >> des;
    int dist[MAX], visit[MAX], number[MAX], teams[MAX];
    for (int i = 0; i < n; i ++) {
        cin >> team[i];
        dist[i] = INF;
        visit[i] = 0;
        number[i] = 0;
        teams[i] = 0;
    }
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (i != j) {
                city[i][j] = city[j][i] = INF;
            }
        }
    }
    int x, y, d;
    for (int i = 0; i < m; i ++) {
        cin >> x >> y >> d;
        city[x][y] = d;
        city[y][x] = d;
    }
    dist[src] = 0;
    number[src] = 1;
    teams[src] = team[src];
    for (int i = 0; i < n; i ++) {
        int u = -1, min_dist = INF;
        for (int j = 0; j < n; j ++) {
            if (visit[j] == 0 && dist[j] < min_dist) {
                u = j;
                min_dist = dist[j];
            }
        }
        if (u == -1) {
            break;
        }
        visit[u] = 1;
        for(int v = 0; v < n; v ++) {
            if (visit[v] == 0 && city[u][v] != INF) {
                if (dist[u] + city[u][v] < dist[v]) {
                    dist[v] = dist[u] + city[u][v];
                    number[v] = number[u];
                    teams[v] = teams[u] + team[v];
                } else if (dist[u] + city[u][v] == dist[v]) {
                    number[v] += number[u];
                    if (teams[u] + team[v] > teams[v]) {
                        teams[v] = teams[u] + team[v];
                    }
                }
            }
        }
    }
    cout << number[des] << " " << teams[des];
    return 0;
}