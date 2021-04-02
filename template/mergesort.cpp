#include <iostream>
using namespace std;

int a[10] = {2, 7, 3, 6, 4, 10, 0, 90, -1, 8};

void merge_sort(int a[], int b[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    merge_sort(a, b, left, mid);
    merge_sort(a, b, mid + 1, right);
    // 一串的经典归并排序代码

}


int main() {
    
    for (int i = 0; i < 10; i ++) {
        cout << a[i] << " ";
    }
    return 0;
}