// 错误解答，18、25 一个点超时一个点错误
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<int, int> mp;
int num[11][1001] = {0};
int isout[11] = {0};

int main()
{
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    mp[a] = 1;
    mp[b] = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            scanf("%d ", &num[i][j]);
        }
    }
    for (int j = 1; j <= m; j ++) {
        for (int i = 1; i <= n; i ++) {
            if (isout[i]) {
                continue;
            }
            if (mp[num[i][j]] == 1) {
                printf("Round #%d: %d is out.\n", j, i);
                isout[i] = 1;
                continue;
            }
            int out = 1;
            for (auto it = mp.begin(); it != mp.end(); it ++) {
                //cout << it->first << " " << it->second << endl;
                if (it->first >= num[i][j] && mp[it->first - num[i][j]] == 1) {
                    // cout << j << " " << i << "found " << it->first - num[i][j] << endl;
                    out = 0;
                    break;
                }
            }
            if (out) {
                printf("Round #%d: %d is out.\n", j, i);
                isout[i] = 1;
            }
            mp[num[i][j]] = 1;
        }
    }
    vector<int> res;
    for (int i = 1; i <= n; i ++) {
        if (isout[i] == 0) {
            res.push_back(i);
        }
    }
    if (res.size() == 0) {
        cout << "No winner." << endl;
    } else {
        printf("Winner(s):");
        for (int i = 0; i < res.size(); i ++) {
            printf(" %d", res[i]);
        }
        printf("\n");
    }
    return 0;
}