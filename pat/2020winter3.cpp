#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int n, num;
    cin >> n;
    getchar();
    int last[1001] = {0}, root[10001];
    map<int, int> mp;
    stack<int> path;
    for (int i = 0; i < 10001; i ++) {
        root[i] = -1;
    }
    for (int i = 0; i < n; i ++) {
        string s;
        int d = 0, num;
        getline(cin, s);
        while (s[d] == ' ') {
            d ++;
        }
        num = atoi(s.substr(d).c_str());
        mp[num] = d;
        if (num == 0) {
            path.push(num);
            continue;
        }
        int p = path.top();
        if (d <= mp[p]) {
            while (d <= mp[p]) {
                path.pop();
                p = path.top();
            }
        }
        root[num] = p;
        path.push(num);
    }
    int k, query;
    cin >> k;
    for (int i = 0; i < k; i ++) {
        cin >> query;
        if (query == 0) {
            cout << "0000" << endl;
        } else if (mp[query] == 0) {
            printf("Error: %04d is not found.\n", query);
        } else {
            vector<int> res;
            int x = query;
            while (x != -1) {
                res.push_back(x);
                x = root[x];
            }
            for (int j = res.size() - 1; j >= 0; j --) {
                printf("%04d", res[j]);
                if (j != 0) {
                    printf("->");
                }
            }
            printf("\n");
        }
    }
    return 0;
}