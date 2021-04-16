/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */
#include <vector>
using namespace std;
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
    vector<vector<int>> res;
    vector<int> temp;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        travel(root, targetSum);
        return res;
    }

    void travel(TreeNode* root, int target) {
        if (root == nullptr) {
            return;
        }
        temp.push_back(root->val);
        target -= root->val;
        if (target == 0 && root->left == nullptr && root->right == nullptr) {
            res.push_back(temp);
        }
        travel(root->left, target);
        travel(root->right, target);
        temp.pop_back();
        return;
    }
};

// @lc code=end

