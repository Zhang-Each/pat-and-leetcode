#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

map<string, set<int>> student;

int main()
{
    int n, k, m, id;
    string s;
    cin >> n >> k;
    for (int i = 0; i < k; i ++) {
        cin >> id >> m;
        for (int j = 0; j < m; j ++) {
            cin >> s;
            student[s].insert(id);
        }
    }
    for (int i = 0; i < n; i ++) {
        cin >> s;
        set<int>::iterator it;
        cout << s << " " << student[s].size();
        for (it = student[s].begin(); it != student[s].end(); it ++) {
            cout << " " << *it;
        }
        cout << endl;
    }
    return 0;
}