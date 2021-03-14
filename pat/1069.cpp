#include <iostream>
#include <algorithm>
using namespace std;

int getMax(int n) {
    int num = 0;
    int a[4] = {0};
    while (n > 0) {
        a[num++] = n % 10;
        n /= 10;
    }
    sort(a, a + 4);
    return a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0];
}

int getMin(int n) {
    int num = 0;
    int a[4] = {0};
    while (n > 0) {
        a[num++] = n % 10;
        n /= 10;
    }
    sort(a, a + 4);
    return a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
}

int main()
{
    int res;
    cin >> res;
    if (res == 6174) {
        printf("7641 - 1467 = 6174\n");
        return 0;
    }
    while (res != 6174 && res != 0) {
        int x = getMax(res), y = getMin(res);
        res = x - y;
        printf("%04d - %04d = %04d\n", x, y, res);
    }
    return 0;
}