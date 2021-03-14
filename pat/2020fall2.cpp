#include <iostream>
using namespace std;

int main()
{
    int n, m, count = 0;
    cin >> n >> m;
    int *a = new int[n];
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i ++) {
        int sum = 0;
        for (int j = i; j < n; j ++) {
            sum += a[j];
            if (sum <= m) {
                count += 1;
            } else {
                break;
            }
        }
    }
    cout << count << endl;
}