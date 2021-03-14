#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, m, x;
    cin >> n >> m;
    vector<int> nums;
    priority_queue<int, vector<int>, greater<int>> q1, q2;
    for (int i = 0; i < n; i ++) {
        cin >> x;
        nums.push_back(x);
    };
    int i = 0;
    while (true) {
        while (i < n && q1.size() < m) {
            q1.push(nums[i++]);
        }
        vector<int> res;
        while (!q1.empty()) {
            int now = q1.top();
            q1.pop();
            res.push_back(now);
            if (i < n) {
                int next = nums[i++];
                if (next <= now) {
                    q2.push(next);
                } else {
                    q1.push(next);
                }
            }
        }
        for (int j = 0; j < res.size(); j ++) {
            if (j != 0) {
                cout << " ";
            }
            cout << res[j];
        }
        cout << endl;
        while (!q2.empty()) {
            q1.push(q2.top());
            q2.pop();
        }
        if (q1.size() == 0 && i == n) {
            break;
        }
    }
    return 0;
}