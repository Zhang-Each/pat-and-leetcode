/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        queue<Node*> q;
        q.push(root);
        while (q.size() != 0) {
            int count = q.size();
            vector<int> temp;
            while (count > 0) {
                Node *p = q.front();
                q.pop();
                count -= 1;
                temp.push_back(p->val);
                for (int i = 0; i < p->children.size(); i ++) {
                    if (p->children[i] != nullptr) {
                        q.push(p->children[i]);
                    }
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
// @lc code=end

