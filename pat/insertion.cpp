#include <iostream>
using namespace std;

int main()
{
    int a[10] = {123, 21, 76, 45, 67, 99, 11, 45, 0, 87};
    for (int p = 1; p < 10; p ++) {
        int j, temp = a[p];
        for (j = p; j > 0 && a[j - 1] > temp; j --) {
            a[j] = a[j - 1];
        }
        a[j] = temp;
    }
    for (int i = 0; i < 10; i ++) {
        cout << a[i] << " ";
    }
    return 0;
}