#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, found = 0;
    cin >> n;
    int i, len = 0;
    for (int start = 2; start <= sqrt(n); start++) {
        long long temp = 1;
        int end = start;
        while (1) {
            temp *= end++;
            if (n % temp != 0) {
                break;
            }
            if (end - start > len) {
                len = end - start;
                i = start;
            }
        }
    }

    if (len == 0) {
        cout << 1 << endl << n << endl;
    } else {
        cout << len << endl;
        for (int j = i; j < i + len; j++) {
            cout << j;
            if (j != i + len - 1) {
                cout << "*";
            }
        }
    }
    return 0;
}