#include <iostream>
using namespace std;

int main()
{
    int n, num, count = 0;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i ++) {
        cin >> num;
        a[num] = i;
    }
    for (int i = 0; i < n; i ++) {
        if (a[i] != i) {
            while (a[0] != 0) {
                swap(a[0], a[a[0]]);
                count += 1;
            }
            if (a[i] != i) {
                swap(a[0], a[i]);
                count += 1;
            }
        }
    }
    cout << count << endl;
    return 0;
}