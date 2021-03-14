#include <iostream>
#include <map>
using namespace std;

map<int, int> num;

int main()
{
    int n, m, s, found = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        cin >> s;
        num[s] += 1;
    }
    map<int, int>::iterator it;
    for (it = num.begin(); it != num.end(); it ++) {
        if (it->first * 2 == m && it->second >= 2) {
            cout << it->first << " " << it->first << endl;
            found = 1;
            break;
        } else if (it->first * 2 != m && it->second >= 1 && num[m - it->first] >= 1) {
            cout << it->first << " " << m - it->first << endl;
            found = 1;
            break;
        }
    }
    if (found == 0) {
        cout << "No Solution" << endl;
    }
    return 0;
}