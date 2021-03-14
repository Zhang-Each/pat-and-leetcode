#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

#define MAX 201
int r[MAX][MAX] = {0};

int main()
{
    int n, m, k, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        cin >> a >> b;
        r[a][b] = r[b][a] = 1;
    }
    cin >> k;
    for (int i = 1; i <= k; i ++) {
        int d, x, error = 0;
        cin >> d;
        int *a = new int[d];
        map<int, int> mp;
        set<int> miss;
        for (int j = 0; j < d; j ++) {
            cin >> a[j];
            mp[a[j]] = 1;
        }
        for (int j = 0; j < d; j ++) {
            if (error) {
                break;
            }
            for (int l = 1; l <= n; l ++) {
                if (r[a[j]][l] == 1 && mp[l] == 0) {
                    // l和a[j]有关系但是没有出现过
                    int flag = 1;
                    for (int z = 0; z < d; z ++) {
                        if (r[l][a[z]] == 0) {
                            flag = 0;
                        }
                    }
                    if (flag) {
                        miss.insert(l);
                    }
                }
                if (a[j] != l && r[a[j]][l] == 0 && mp[l] == 1) {
                    error = 1;
                    break;
                }
            }
        }
        if (error) {
            printf("Area %d needs help.\n", i);
        } else {
            if (miss.empty()) {
                printf("Area %d is OK.\n", i);
            } else {
                printf("Area %d may invite more people, such as %d.\n", i, *(miss.begin()));
            }
        }
    }
    return 0;
}