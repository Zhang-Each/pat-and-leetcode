#include <iostream>
#include <string>
using namespace std;

string look(string s) {
    string res = "";
    int count = 1;
    int i = 1;
    while (i < s.size()) {
        if (s[i] == s[i - 1]) {
            count += 1;
        } else {
            res += s[i - 1];
            res += '0' + count;
            count = 1;
        }
        i ++;
    }
    res += s[i - 1];
    res += '0' + count;
    // cout << res << endl;
    return res;
}

int main()
{
    string s;
    int n;
    cin >> s >> n;
    string *res = new string[n];
    res[0] = s;
    for (int i = 1; i < n; i ++) {
        res[i] = look(res[i - 1]);
    }
    cout << res[n - 1] << endl;
    return 0;
}