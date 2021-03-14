#include <iostream>
#include <set>
using namespace std;

#define MAX 201
int g[MAX][MAX] = {0};

int main()
{
    int n, m, k;
    int a, b ,d;
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        cin >> a >> b >> d;
        g[a][b] = g[b][a] = d;
    }
    cin >> k;
    int min_dist = 10000000, mini = -1;
    for (int i = 1; i <= k; i ++) {
        int len, dist = 0;
        cin >> len;
        int* a = new int[len];
        set<int> s;
        for (int j = 0; j < len; j ++) {
            cin >> a[j];
            s.insert(a[j]);
        }
        for (int i = 0; i < len - 1; i ++) {
            if (g[a[i]][a[i + 1]] != 0) {
                dist += g[a[i]][a[i + 1]];
            } else {
                dist = -1;
                break;
            }
        }
        if (dist == -1) {
            printf("Path %d: NA (Not a TS cycle)\n", i);
        } else {
            if (s.size() < n || len < n || a[0] != a[len - 1]) {
                printf("Path %d: %d (Not a TS cycle)\n", i, dist);
                continue;
            } else if (s.size() == n && len == n + 1) {
                printf("Path %d: %d (TS simple cycle)\n", i, dist);
            } else {
                printf("Path %d: %d (TS cycle)\n", i, dist);
            }
            if (dist < min_dist) {
                min_dist = dist;
                mini = i;
            }
        }
    }
    printf("Shortest Dist(%d) = %d", mini, min_dist);
    return 0;
}