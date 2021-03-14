/*
 * @lc app=leetcode.cn id=703 lang=java
 *
 * [703] 数据流中的第 K 大元素
 */

// @lc code=start
import java.util.*;

class KthLargest {
    private int k;
    private PriorityQueue<Integer> heap;
    public KthLargest(int k, int[] nums) {
        this.k = k;
        this.heap = new PriorityQueue<Integer>(k);
        for (int i = 0; i < nums.length; i++) {
            this.add(nums[i]);
        }
    }
    
    public int add(int val) {
        if (heap.size() < k) {
            heap.add(val);
        } else if (heap.peek() < val){
            heap.poll();
            heap.add(val);
        }
        return heap.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
// @lc code=end

