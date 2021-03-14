#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int res = 0;

void find_a_little(string s) {
    if (s == "0" || s .size() == 0) {
        return;
    } else if (s.size() == 1) {
        res += 1;
        return;
    }
    int num = s[0] - '0';
    for (int i = 0; i < num; i ++) {
        res += pow(10, s.size() - 2) * (s.size() - 1);
        if (i == 1) {
            res += pow(10, s.size() - 1);
        }
    }
    string t = s.substr(1, s.size() - 1);
    if (num == 1) {
        res += atoi(t.c_str()) + 1;
    }
    find_a_little(t);
}

int main() {
    
    string s;
    cin >> s;
    find_a_little(s);
    cout << res << endl;
    return 0;
}