/*
 * @lc app=leetcode.cn id=225 lang=java
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
    private Queue<Integer> a, b;
    /** Initialize your data structure here. */
    public MyStack() {
        a = new LinkedList<>();
        b = new LinkedList<>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        a.offer(x);
        while (b.size() > 0) {
            a.offer(b.poll());
        }
        Queue<Integer> t = a;
        a = b;
        b = t;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return b.poll();
    }
    
    /** Get the top element. */
    public int top() {
        return b.peek();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return b.size() == 0;
    }
}
// @lc code=end

