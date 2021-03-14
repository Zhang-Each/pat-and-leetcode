#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 101
int a[MAX] = {0}, b[MAX] = {0}, c[MAX];

bool compare(int x[], int y[], int len) {
    for (int i = 0; i < len; i ++) {
        if (x[i] != y[i]) {
            return false;
        }
    }
    return true;
}

void show(int a[], int n) {
    for (int i = 0; i < n; i ++) {
        if (i != 0) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        c[i] = a[i];
    }
    for (int i = 0; i < n; i ++) {
        cin >> b[i];
    }
    int temp, flag = 0;
    for (int p = 1; p < n; p ++) {
        temp = a[p];
        int j;
        for (j = p; j > 0 && a[j - 1] > temp; j --) {
            a[j] = a[j - 1]; 
        }
        a[j] = temp;
        if (flag) {
            break;
        }
        if (compare(a, b, n)) {
            flag = 1;
            cout << "Insertion Sort" << endl;
        }
    }
    if (flag) {
        show(a, n);
        return 0;
    }
    cout << "Merge Sort" << endl;
    int k = 1, f = 1;
    while (f) {
        f = 0;
        for (int i = 0; i < n; i ++) {
            if (c[i] != b[i]) {
                f = 1;
            }
        }
        k = k * 2;
        for (int i = 0; i < n / k; i ++) {
            sort(c + i * k, c + (i + 1) * k);
        }
        sort(c + n / k * k, c + n);
    }
    show(c, n);
    return 0;
}