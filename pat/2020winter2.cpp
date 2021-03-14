// 23/25 有一个点莫名其妙答案错误
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    if (t.size() == 1) {
        cout << t << endl;
        return 0;
    }
    vector<int> start, end;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == t[0]) {
            start.push_back(i);
        }
    }
    string res;
    int len = 100000000;
    for (int i = 0; i < start.size(); i ++) {
        int j = start[i], k = 0;
        while (j < s.size() && k < t.size()) {
            if (s[j] == t[k]) {
                k += 1;
            }
            j += 1;
        }
        if (k == t.size() && j - start[i] < len) {
            res = s.substr(start[i], j - start[i]);
            len = j - start[i];
        }
    }
    cout << res << endl;
}