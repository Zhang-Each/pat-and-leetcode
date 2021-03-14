#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000

set<int> danger[MAX];

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        cin >> a >> b;
        danger[a].insert(b);
        danger[b].insert(a);
    }
    for (int i = 0; i < m; i ++) {
        cin >> a;
        vector<int> temp;
        for (int j = 0; j < a; j ++) {
            cin >> b;
            temp.push_back(b);
        }
        int flag = 0;
        for (int j = 0; j < a; j ++) {
            for (int k = j + 1; k < a; k ++) {
                if (danger[temp[j]].find(temp[k]) != danger[temp[j]].end()) {
                    cout << "No" << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                break;
            }
        }
        if (flag == 0) {
            cout << "Yes" << endl;
        }
    } 
    return 0;
}