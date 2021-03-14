#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<string> course[2501];
    for (int i = 0; i < n; i ++) {
        string name;
        int m, c;
        cin >> name >> m;
        for (int j = 0; j < m; j ++) {
            cin >> c;
            course[c].push_back(name);
        }
    }
    for (int i = 1; i <= k; i++) {
        cout << i << " " << course[i].size() << endl;
        sort(course[i].begin(), course[i].end());
        for (int j = 0; j < course[i].size(); j ++) {
            printf("%s\n", course[i][j].c_str());
        }
    }
    return 0;
}