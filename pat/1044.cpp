// 好题
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, target, left = 0, find = 0, minsum = 999999999;
    cin >> n >> target;
    int *a = new int [n + 1];
    int *sum = new int[n + 1];
    sum[0] = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        while (sum[i] - sum[left] > target) {
            minsum = min(minsum, sum[i] - sum[left]);
            left ++;
        }
        if (sum[i] - sum[left] == target) {
            cout << left + 1 << "-" << i << endl;
            find = 1;
        }
    }
    if (!find) {
        left = 0;
        for (int i = 1; i <= n; i ++) {
            while (sum[i] - sum[left] > minsum) {
                left ++;
            }
            if (sum[i] - sum[left] == minsum) {
                cout << left + 1 << "-" << i << endl;
            }
        } 
    }
    return 0;
}