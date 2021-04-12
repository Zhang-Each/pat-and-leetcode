/*
 * @lc app=leetcode.cn id=155 lang=java
 *
 * [155] 最小栈
 */

// @lc code=start
import java.util.*;
class MinStack {
    private int length = 0;
    private int min;
    private Vector<Integer> stack;
    /** initialize your data structure here. */
    public MinStack() {
        this.stack = new Vector<Integer>();
    }
    
    public void push(int x) {
        if (length == 0) {
            min = x;
        } else {
            min = min > x ? x : min;
        }
        length ++;
        stack.add(x);
    }
    
    public void pop() {
        int x = stack.elementAt(length - 1);
        stack.remove(length - 1);
        length -= 1;
        if (min == x && length >= 1) {
            min = stack.elementAt(0);
            for (int i = 0; i < length; i++) {
                if (min > stack.elementAt(i)) {
                    min = stack.elementAt(i);
                }
            }
        }
    }
    
    public int top() {
        return stack.elementAt(length - 1);
    }
    
    public int getMin() {
        return min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
// @lc code=end

