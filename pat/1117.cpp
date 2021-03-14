#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int i, j, n, res = 0;
    cin >> n;
    int *a = new int[n];
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (i = n - 1, res = 1; i >= 0; i--, res++) {
        if (a[i] <= res)
            break;
    }
    cout << res - 1 << endl;
    return 0;
}