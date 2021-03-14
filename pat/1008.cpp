#include <iostream>
using namespace std;

int main ()
{
    int n, sum = 0;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
        sum += 5;
    }
    int up = 6, down = 4;
    sum += up * a[0];
    for (int i = 1; i < n; i ++ ) {
        int delta = a[i] - a[i - 1];
        if (delta < 0) {
            sum -= delta * down;
        } else {
            sum += delta * up;
        }
    }
    cout << sum << endl;
    return 0;
}