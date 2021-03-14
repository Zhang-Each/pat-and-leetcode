#include <iostream>
using namespace std;

int main()
{
    int n, cycle = 0, x, y, c;
    cin >> n;
    int *a = new int[n];
    int *d = new int[n];
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        cycle += a[i];
        d[i] = 0;
        if (i >= 1) {
            d[i] = d[i - 1] + a[i - 1];
        }
    }
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> x >> y;
        int dist = abs(d[x - 1] - d[y - 1]);
        cout << min(dist, cycle - dist) << endl;
    }
    return 0;
}