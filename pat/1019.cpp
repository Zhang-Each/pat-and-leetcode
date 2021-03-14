#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;

bool isPalindromic() {
    for (int i = 0; i < nums.size(); i ++) {
        if (nums[i] != nums[nums.size() - i -1]) {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, b;
    cin >> n >> b;
    while (n != 0) {
        nums.push_back(n % b);
        n /= b;
    }
    if (isPalindromic()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    for (int i = nums.size() - 1; i >= 0; i --) {
        cout << nums[i];
        if (i != 0) {
            cout << " ";
        }
    }
    return 0;
}