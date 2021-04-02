#include <iostream>
using namespace std;

int a[10] = {2, 7, 3, 6, 4, 10, 0, 90, -1, 8};

void quick_sort(int a[], int left, int right) {
    if (right <= left) {
        return;
    }
    int i = left, j = right, x = a[left];
    while (i < j) {
        while (i < j && a[j] >= x) {
            j --;
        }
        if (i < j) {
            a[i ++] = a[j];
        }
        while (i < j && a[i] < x) {
            i ++;
        }
        if (i < j) {
            a[j --] = a[i];
        }
    }    
    a[i] = x;
    quick_sort(a, left, i - 1);
    quick_sort(a, i + 1, right);
}

int main() {
    quick_sort(a, 0, 9);
    for (int i = 0; i < 10; i ++) {
        cout << a[i] << " ";
    }
    return 0;
}