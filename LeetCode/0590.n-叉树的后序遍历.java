/*
 * @lc app=leetcode.cn id=590 lang=java
 *
 * [590] N 叉树的后序遍历
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
    List<Integer> res = new ArrayList<Integer>();
    public List<Integer> postorder(Node root) {
        travel(root);
        return res;
    }

    private void travel(Node root) {
        if (root != null) {
            for (int i = 0; i < root.children.size(); i ++) {
                travel(root.children.get(i));
            }
            res.add(root.val);
        }
    }
}

// @lc code=end

