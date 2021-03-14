#include <iostream>
using namespace std;

double p[1001] = {0};

void read() {
    int n, ex;
    double s;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> ex >> s;
        p[ex] += s;
    }
}

int main()
{
    read();
    read();
    int count = 0;
    for (int i = 0; i <= 1000; i ++) {
        if (p[i] != 0) {
            count ++;
        }
    }
    cout << count;
    for (int i = 1000; i >= 0; i --) {
        if (p[i] != 0) {
            printf(" %d %.1f", i, p[i]);
        }
    }
    return 0;
}