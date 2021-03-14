#include <iostream>
using namespace std;

int main()
{
    double x[1001] = {0}, y[1001] = {0};
    int n, e, count = 0;
    double s;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> e >> s;
        x[e] = s;
    }
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> e >> s;
        y[e] = s;
    }
    double res[2002] = {0};
    for (int i = 0; i <= 1000; i ++) {
        for (int j = 0; j <= 1000; j ++) {
            res[i + j] += x[i] * y[j];
        }
    }
    for (int i = 0; i <= 2001; i ++) {
        if (res[i] != 0) {
            count += 1;
        }
    }
    cout << count;
    for (int i = 2001; i >= 0; i --) {
        if (res[i] != 0) {
            printf(" %d %.1f", i, res[i]);
        }
    }
    return 0;
}