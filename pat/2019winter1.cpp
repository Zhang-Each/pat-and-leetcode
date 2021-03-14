#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s[26][7], t;
    for (int i = 0; i < 26; i ++) {
        for (int j = 0; j < 7; j ++) {
            cin >> s[i][j];
        }
    }
    getchar();
    getline(cin, t);
    vector<string> res;
    string temp;
    for (int i = 0; i < t.size(); i ++) {
        if (t[i] >= 'A' && t[i] <= 'Z') {
            temp += t[i];
        } else {
            res.push_back(temp);
            temp = "";
        }
    }
    if (temp != "") {
        res.push_back(temp);
    }
    int has = 0;
    for (int i = 0; i < res.size(); i ++) {
        if (res[i] == "") {
            continue;
        }
        if (i != 0 && has) {
            cout << endl;
        }
        for (int j = 0; j < 7; j ++) {
            has = 1;
            for (int k = 0; k < res[i].size(); k ++) {
                if (k != 0) {
                    cout << " ";
                }
                cout << s[res[i][k] - 'A'][j];
            }
            cout << endl;
        }
    }
    return 0;
}