#include <iostream>
using namespace std;

int main()
{
    int a[45], n;
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i < 45; i ++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    cin >> n;
    for (int i = 0; i <= 44; i ++) {
        if (n >= a[i] && n < a[i + 1]) {
            if (n - a[i] > a[i + 1] - n) {
                cout << a[i + 1] << endl;
            } else {
                cout << a[i] << endl;
            }
            break;
        }
    }
    return 0;
}