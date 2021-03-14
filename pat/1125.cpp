#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a, a + n);
    double res = 1.0 * a[0];
    for (int i = 1; i < n; i ++) {
        res = (res + a[i]) / 2;
    }
    cout << (int)res << endl;
    return 0;
}