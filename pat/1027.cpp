#include <iostream>
using namespace std;

void show(int x) {
    if (x <= 9) {
        cout << x;
    } else {
        char y = 'A' + x - 10;
        cout << y;
    }
}

int main()
{
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    cout << "#";
    for (int i = 0; i < 3; i ++) {
        int x = a[i] / 13, y = a[i] % 13;
        show(x);
        show(y);
    }
    return 0;
}