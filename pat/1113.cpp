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
    long long res = 0;
    for (int i = 0; i < n / 2; i ++) {
        res -= a[i];
    }
    for (int i = n / 2; i < n; i ++) {
        res += a[i];
    }
    if (n % 2 == 0) {
        cout << 0 << " " << res << endl;
    } else {
        cout << 1 << " " << res << endl;
    }
    return 0;
}