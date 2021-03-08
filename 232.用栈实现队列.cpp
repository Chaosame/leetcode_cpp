/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int>s1; //用来入队
    stack<int>s2; //用来出队
    int front; //记录队列头元素
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(s1.empty()){
            front = x;
        }
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                int t = s1.top();
                s2.push(t);
                s1.pop();
            }
        }
        int res = s2.top();
        s2.pop();
        return res;

    }
    
    /** Get the front element. */
    int peek() {
        if (!s2.empty()){
            return s2.top();
        }
        else return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return(s1.empty()&&s2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

