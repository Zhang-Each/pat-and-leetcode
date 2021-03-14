#include <iostream>
using namespace std;
#define MAX 101
#define left(i) (2 * (i) + 1)

int a[MAX] = {0}, b[MAX] = {0}, c[MAX];

bool compare(int x[], int y[], int len) {
    for (int i = 0; i < len; i ++) {
        if (x[i] != y[i]) {
            return false;
        }
    }
    return true;
}

void down(int a[], int i, int n) {
    int child, tmp;
    for (tmp = a[i]; left(i) < n; i = child) {
        child = left(i);
        if (child != n - 1 && a[child + 1] > a[child])
            child++;
        if (a[child] > tmp)
            a[i] = a[child];
        else
            break;
    }
    a[i] = tmp;
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
    int temp, flag = 1;
    for (int p = 1; p < n; p ++) {
        temp = c[p];
        int j;
        for (j = p; j > 0 && c[j - 1] > temp; j --) {
            c[j] = c[j - 1];
        }
        c[j] = temp;
        if (!flag) {
            break;
        }
        if (compare(b, c, n)) {
            cout << "Insertion Sort" << endl;
            flag = 0;
        }
    }
    if (!flag) {
        for (int i = 0; i < n; i ++) {
            if (i != 0) {
                cout << " ";
            }
            cout << c[i];
        }
        return 0;
    }
    cout << "Heap Sort" << endl;
    for (int i = n / 2; i >= 0; i --) {
        down(a, i, n);
    }
    int flag2 = 0;
    for (int i = n - 1; i > 0; i --) {
        swap(a[0], a[i]);
        down(a, 0, i);
        if (flag2) {
            break;
        }
        if (compare(a, b, n)) {
            flag2 = 1;
        }
    }
    for (int i = 0; i < n; i ++) {
        if (i != 0) {
            cout << " ";
        }
        cout << a[i];
    }
    return 0;
}