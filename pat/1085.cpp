#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, p, len = 1;
    cin >> n >> p;
    int *a = new int[n];
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i ++) {
        while (i - 1 + len < n && a[i - 1 + len] <= p * a[i]) {
            len += 1;
        }
    }
    cout << len - 1 << endl;
    return 0;
}