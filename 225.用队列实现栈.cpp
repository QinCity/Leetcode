/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
    queue<int> q, q_tmp;
public:
    MyStack() {
        
    }
    
    // void push(int x) {
    //     while (!q.empty()) {
    //         q_tmp.push(q.front());
    //         q.pop();
    //     }        
    //     q.push(x);
    //     while (!q_tmp.empty()) {
    //         q.push(q_tmp.front());
    //         q_tmp.pop();
    //     }
    // }

    void push(int x) {
        if (q.empty()){
            q.push(x);
            return;
        }
        int tmp = q.front();
        q.pop();
        this->push(x);
        q.push(tmp);
    }

    
    int pop() {
        int result = q.front();
        q.pop();
        return result;    
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();    
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

