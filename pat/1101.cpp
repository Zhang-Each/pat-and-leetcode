#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, int> res;

int main()
{
    int n, a, left_max = -1, right_min = 1000000001;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a;
        nums.push_back(a);
    }
    for (int i = 0; i < nums.size(); i ++) {
        if (left_max < nums[i]) {
            res[nums[i]] += 1;
        }
        if (left_max < nums[i]) {
            left_max = nums[i];
        }
    }
    for (int i = nums.size() - 1; i >= 0; i --) {
        if (right_min > nums[i]) {
            res[nums[i]] += 1;
        }
        if (right_min > nums[i]) {
            right_min = nums[i];
        }
    }
    vector<int> part;
    map<int, int>::iterator it = res.begin();
    while (it != res.end()) {
        if (it->second == 2) {
            part.push_back(it->first);
        }
        it ++;
    }
    cout << part.size() << endl;
    for (int i = 0; i < part.size(); i ++) {
        if (i != 0) {
            cout << " ";
        }
        cout << part[i];
    }
    cout << endl;
    return 0;
}