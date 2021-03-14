/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }
        stack<TreeNode*> s;
        s.push(root);
        while (s.size() != 0) {
            root = s.top();
            s.pop();
            if(root->left) {
                s.push(root->left);
            }
            if(root->right) {
                s.push(root->right);
            }
            res.push_back(root->val);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

