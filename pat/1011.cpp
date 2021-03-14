#include <iostream>
#include <stdio.h>

using namespace std;

int main () 
{
    string s;
    double res = 1.0;
    for (int i = 0; i < 3; i ++) {
        int maxj = 0;
        double maxp = 0, p;
        for (int j = 0; j < 3; j ++) {
            cin >> p;
            if (p > maxp) {
                maxp = p;
                maxj = j;
            }
        }
        if (maxj == 0) {
            s += 'W';
        } else if (maxj == 1) {
            s += 'T';
        } else {
            s += 'L';
        }
        s += ' ';
        res *= maxp;
    }
    res = (res * 0.65 - 1) * 2;
    printf("%s%.2f", s.c_str(), res);
    return 0;
}