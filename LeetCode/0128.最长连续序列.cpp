class Solution {
public:
    // n个数建立堆的时间复杂度是o(n)
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < nums.size(); i ++) {
            q.push(nums[i]);
        }
        int maxlen = 1, len = 1, cur, last = q.top();
        q.pop();
        while (!q.empty()) {
            cur = q.top();
            q.pop();
            //cout << cur << " " << last << endl;
            if (cur == last + 1) {
                len ++;
            } else if (cur == last) {
                continue;
            } else {
                maxlen = len > maxlen ? len : maxlen;
                len = 1;
            }
            last = cur;
        }
        maxlen = len > maxlen ? len : maxlen;
        return maxlen;
    }
};