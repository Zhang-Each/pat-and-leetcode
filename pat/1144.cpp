#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n, t;
    set<int> s;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> t;
        s.insert(t);
    }
    int res = 1;
    while (1) {
        if (s.find(res) == s.end()) {
            cout << res << endl;
            break;
        }
        res += 1;
    }
    return 0;
}