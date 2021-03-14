#include <iostream>
#include <string>
using namespace std;
#define MAX 10001

int dp[MAX][MAX] = {0};

int main()
{
    string s;
    getline(cin, s);
    if (s.size() <= 1) {
        cout << s.size() << endl;
        return 0;
    }
    int res = 1;
    for (int i = s.size() - 1; i >= 0; i --) {
        dp[i][i] = 1;
        for (int j = i + 1; j < s.size(); j ++) {
            if (j == i + 1 && s[i] == s[j]) {
                dp[i][j] = 1;
            } else if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            }
            if (dp[i][j] && j - i + 1 > res) {
                res = j - i + 1;
            }
        }
    }
    cout << res << endl;
    return 0;
}