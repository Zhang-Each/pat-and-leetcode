#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string s, string t) {
    return s + t < t + s;
}

int main()
{
    int i, j, n;
    cin >> n;
    string *s = new string[n];
    for (i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s, s + n, cmp);
    string result = "";
    for (i = 0; i < n; i++) {
        result += s[i];
    }
    i = 0;
    while (result[i] == '0') {
        i++;
    }
    if (i == result.length()) {
        cout << "0" << endl;
    } else {
        for (j = i; j < result.length(); j++) {
            cout << result[j];
        }
    }
    return 0;
}