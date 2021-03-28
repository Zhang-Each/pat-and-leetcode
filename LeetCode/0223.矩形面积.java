/*
 * @lc app=leetcode.cn id=223 lang=java
 *
 * [223] 矩形面积
 */

// @lc code=start
class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int S = (C - A) * (D - B) + (G - E) * (H - F), s = 0;
        if (E >= C || G <= A || H <= B || F >= D) {
            s = 0;
        } else {
            int x1 = Math.max(A, E);
            int x2 = Math.min(C, G);
        
            int y1 = Math.max(B, F);
            int y2 = Math.min(D, H);
        
            s = (x2 - x1) * (y2 - y1);
        }
        return S - s;
    }
}
// @lc code=end

