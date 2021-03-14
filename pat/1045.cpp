#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int n, num;
    cin >> n;
    map<int, int> color;
    vector<int> a;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> num;
        color[num] = i;
    }
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> num;
        if (color[num] != 0) {
            a.push_back(color[num]);
        }
    }
    // 现在题目变成了求一个单调不减的序列长度的最大值
    int len = 0;
    int *dp = new int[a.size()];
    for (int i = 0; i < a.size(); i ++) {
        dp[i] = 1;
        for (int j = 0; j < i; j ++) {
            if (a[j] <= a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << dp[a.size() - 1] << endl;
}