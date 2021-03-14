// 用map存储的情况下按照顺序遍历一次完成的时候就是最小的结果，不需要遍历所有情况然后排序
// 如果在res中存储了所有可能的情况然后排序，会有一个测试点过不了，只能得26分
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<int, int> nums;
int n, target;
vector<vector<int>> res;

void travel(vector<int> &temp, int sum) {
    if (res.size() > 1) {
        return;
    }
    if (sum == target) {
        res.push_back(temp);
        return;
    }
    for (map<int, int>::iterator it = nums.begin(); it != nums.end(); it ++) {
        if (sum + it->first > target) {
            break;
        }
        if (it->second > 0 && sum + it->first <= target) {
            it->second -= 1;
            temp.push_back(it->first);
            travel(temp, sum + it->first);
            temp.pop_back();
            it->second += 1;
        }
    }
}

/*
bool cmp(vector<int> x, vector<int> y) {
    int len = min(x.size(), y.size());
    for (int i = 0; i < len; i ++) {
        if (x[i] != y[i]) {
            return x[i] < y[i];
        }
    }
    return x.size() < y.size();
}
*/

int main()
{
    int num;
    cin >> n >> target;
    for (int i = 0; i < n; i ++) {
        cin >> num;
        if (num <= target) {
            nums[num] += 1;
        }
    }
    vector<int> temp;
    travel(temp, 0);
    if (res.size() == 0) {
        cout << "No Solution" << endl;
        return 0;
    } 
    //sort(res.begin(), res.begin(), cmp);
    for (int i = 0; i < res[0].size(); i ++) {
        if (i != 0) {
            cout << " ";
        }
        cout << res[0][i];
    }
    return 0;
}