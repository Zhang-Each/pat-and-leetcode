#include <iostream>
#include <vector>
using namespace std;

#define MAX 1001
int graph[MAX][MAX] = {0};

/**
 * 关键在于，在每个点入选拓扑排序的时候，其当前的度数都是0
 * */
int main()
{
    int n, m, l, x, y;
    cin >> n >> m;
    vector<int> res;
    int degree[MAX] = {0}, temp[MAX] = {0};
    for (int i = 0; i < m; i ++) {
        cin >> x >> y;
        graph[x][y] = 1;
        degree[y] += 1;
    }
    cin >> l;

    for (int i = 0; i < l; i ++) {
        int *num = new int[n + 1];
        for (int j = 1; j <= n; j ++) {
            cin >> num[j];
            temp[j] = degree[j];
        }
        for (int j = 1; j <= n; j ++) {
            if (temp[num[j]] == 0) {
                for (int k = 1; k <= n; k++) {
                    if (graph[num[j]][k] == 1) {
                        temp[k] -= 1;
                    } 
                } 
            } else {
                res.push_back(i);
                break;
            }
        }
    }

    for (int i = 0; i < res.size(); i ++) {
        if (i != 0) {
            cout << " ";
        }
        cout << res[i];
    }
    cout << endl;
    
    return 0;
}