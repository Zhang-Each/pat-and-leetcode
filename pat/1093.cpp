#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    long long res = 0;
    int p = 0, pa = 0, pat = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == 'P') {
            p += 1;
        } else if (s[i] == 'A') {
            pa += p;
        } else if (s[i] == 'T') {
            res += pa;
        }
        res = res % 1000000007;
    }
    cout << res << endl;
}