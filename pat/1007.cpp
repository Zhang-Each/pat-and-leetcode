#include <iostream>

using namespace std;

int main ()
{
    int n, count = 0;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
        if (a[i] < 0) {
            count ++;
        }
    }
    if (count == n) {
        cout << "0 " << a[0] << " " << a[n - 1] << endl;
        return 0;
    }
    int max = 0, maxi = 0, maxj = 0;
    for (int i = 0; i < n; i ++ ) {
        int temp = 0;
        for (int j = i; j < n; j ++) {
            temp += a[j];
            if (temp < 0) {
                break;
            }
            if (temp > max) {
                max = temp;
                maxi = a[i];
                maxj = a[j];
            }
        }
    }
    cout << max << " " << maxi << " " << maxj << endl;
    return 0;
}