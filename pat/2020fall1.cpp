// 得分17/20 有个点过不了
#include <iostream>
using namespace std;

int main()
{
    int n, minw = 2000, mini = 0;
    cin >> n;
    int *a = new int[n];
    int *s = new int[n];
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        if (a[i] < minw) {
            minw = a[i];
            mini = i;
        }
    }
    if(n == 0) {
        cout << 0 << endl;
        return 0;
    }
    s[mini] = 0;
    int sum = 200, minww = 0;
    for (int i = mini - 1; i >= 0; i --) {
        if (a[i] > a[i + 1]) {
            s[i] = s[i + 1] + 1;
        } else if (a[i] == a[i + 1]) {
            s[i] = s[i + 1];
        } else {
            s[i] = s[i + 1] - 1;
        }
        if (minww > s[i]) {
            minww = s[i];
        }
    }
    for (int i = 0; i < mini; i ++) {
        sum += 200 + 100 * (s[i] - minww);
        //cout << 200 + 100 * (s[i] - minww) << endl;
    }
    minww = 0;
    for (int j = mini + 1; j < n; j ++) {
        if (a[j] > a[j - 1]) {
            s[j] = s[j - 1] + 1;
        } else if (a[j] == a[j - 1]) {
            s[j] = s[j - 1];
        } else {
            s[j] = s[j - 1] - 1;
        }
        if (s[j] < minww) {
            minww = s[j];
        }
    }
    for (int j = mini + 1; j < n; j ++) {
        sum += 200 + 100 * (s[j] - minww);
        //cout << 200 + 100 * (s[j] - minww) << endl;
    }
    cout << sum << endl;
    return 0;
}