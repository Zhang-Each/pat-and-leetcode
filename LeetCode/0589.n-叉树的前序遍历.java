/*
 * @lc app=leetcode.cn id=589 lang=java
 *
 * [589] N 叉树的前序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<Integer> res = new ArrayList<Integer>();

    public List<Integer> preorder(Node root) {
        travel(root);
        return res;
    }

    private void travel(Node root) {
        if (root != null) {
            res.add(root.val);
            for (int i = 0; i < root.children.size(); i ++) {
                travel(root.children.get(i));
            }
        }
    }
}
// @lc code=end

