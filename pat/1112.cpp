#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int i = 0, k;
    string s, res;
    vector<char> stuck;
    map<char, int> m;
    cin >> k >> s;
    while (i < s.size()) {
        bool dup = true;
        for (int j = i; j < i + k; j ++) {
            if (s[j] != s[i]) {
                dup = false;
            }
        }
        res += s[i];
        if (dup) {
            m[s[i]] += 1;
            if (m[s[i]] == 1) {
                stuck.push_back(s[i]);
            } 
            i += k;
        } else {
            i += 1;
        }
    }
    for (int i = 0; i < stuck.size(); i ++) {
        cout << stuck[i];
    }
    cout << endl << res << endl;
}