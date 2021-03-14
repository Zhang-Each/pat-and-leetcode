#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define MAX 10001

int res[MAX][MAX] = {0};
bool cmp(int x, int y) {
    return x > y;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    int row, col;
    for (col = sqrt(n); col >= 1; col --) {
        if (n % col == 0) {
            row = n / col;
            break;
        }
    }
    int left = 0, right = col - 1, top = 0, bottom = row - 1;
    int i = 0;
    while (i < n) {
        for (int j = left; j <= right; j ++) {
            res[top][j] = a[i++];
        }
        if (i >= n) {
            break;
        }
        top += 1;
        for (int j = top; j <= bottom; j ++) {
            res[j][right] = a[i++];
        }
        if (i >= n) {
            break;
        }
        right -= 1;
        for (int j = right; j >= left; j --) {
            res[bottom][j] = a[i++];
        }
        if (i >= n) {
            break;
        }
        bottom -= 1;
        for (int j = bottom; j >= top; j --) {
            res[j][left] = a[i++];
        }
        if (i >= n) {
            break;
        }
        left += 1;
    }
    for (int i = 0; i < row; i ++) {
        for (int j = 0; j <col; j ++) {
            if (j != 0) {
                cout << " ";
            }
            cout << res[i][j];
        }
        cout << endl;
    }
    return 0;
}