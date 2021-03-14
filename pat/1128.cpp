#include <iostream>
using namespace std;

bool check(int a[], int n) {
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            if (a[i] == a[j] || abs(a[i] - a[j]) == abs(i - j)) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> m;
        int *a = new int[m];
        for (int j = 0; j < m; j ++) {
            cin >> a[j];
            a[j] -= 1;
        }
        if (check(a, m)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}