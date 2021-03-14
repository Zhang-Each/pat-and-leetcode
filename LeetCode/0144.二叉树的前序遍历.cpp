/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
/**
 * 注：递归的方法太常见了，试试迭代的写法
**/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<TreeNode*> stack;
        if (root == NULL) {
            return res;
        }
        stack.push_back(root);
        while (stack.size() != 0) {
            TreeNode* t = stack[stack.size() - 1];
            stack.pop_back();
            res.push_back(t->val);
            if (t->right != NULL) {
                stack.push_back(t->right);
            }
            if (t->left != NULL) {
                stack.push_back(t->left);
            }
        }
        return res;
    }
};
// @lc code=end

