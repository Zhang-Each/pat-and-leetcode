#include <iostream>
using namespace std;

bool isMaxHeap(int a[], int n) {
    for (int i = 0; i < n; i ++) {
        if (2 * i + 1 >= n) {
            break;
        } else if (2 * i + 1 == n - 1) {
            if (a[i] < a[2 * i + 1]) {
                return false;
            }
        } else {
            if (a[i] < a[2 * i + 1] || a[i] < a[2 * i + 2]) {
                return false;
            }
        }
    }
    return true;
}

bool isMinHeap(int a[], int n) {
    for (int i = 0; i < n; i ++) {
        if (2 * i + 1 >= n) {
            break;
        } else if (2 * i + 1 == n - 1) {
            if (a[i] > a[2 * i + 1]) {
                return false;
            }
        } else {
            if (a[i] > a[2 * i + 1] || a[i] > a[2 * i + 2]) {
                return false;
            }
        }
    }
    return true;
}

void travel(int a[], int i, int n) {
    if (i < n) {
        travel(a, 2 * i + 1, n);
        travel(a, 2 * i + 2, n);
        cout << a[i];
        if (i != 0) {
            cout << " ";
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i ++) {
        int *a = new int[n];
        for (int i = 0; i < n; i ++) {
            cin >> a[i];
        }
        if (isMaxHeap(a, n)) {
            cout << "Max Heap" << endl;
        } else if (isMinHeap(a, n)) {
            cout << "Min Heap" << endl;
        } else {
            cout << "Not Heap" << endl;
        }
        travel(a, 0, n);
        cout << endl;
    }
    return 0;
}