#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> c_pos, c_neg, p_pos, p_neg;
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> num;
        if (num > 0) {
            c_pos.push_back(num);
        } else if (num < 0) {
            c_neg.push_back(num);
        }
    }
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> num;
        if (num > 0) {
            p_pos.push_back(num);
        } else if (num < 0) {
            p_neg.push_back(num);
        }
    }
    int res = 0;
    sort(c_pos.begin(), c_pos.end());
    sort(c_neg.begin(), c_neg.end());
    sort(p_pos.begin(), p_pos.end());
    sort(p_neg.begin(), p_neg.end());
    for (int i = 0, j = 0; i < c_neg.size() && j < p_neg.size(); i ++, j ++) {
        res += c_neg[i] * p_neg[j];
    }
    for (int i = c_pos.size() - 1, j = p_pos.size() - 1; i >= 0 && j >= 0; i --, j --) {
        res += c_pos[i] * p_pos[j];
    }
    cout << res << endl;
}