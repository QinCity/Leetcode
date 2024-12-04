/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    MyQueue() {
        this->st.push_back(stack<int>());
        this->st.push_back(stack<int>());
    }
    
    void push(int x) {
        st[0].push(x);    
    }
    
    int pop() {
        int result;
        while (st[0].size() > 0) {
            st[1].push(st[0].top());
            st[0].pop();
        }
        result = st[1].top();
        st[1].pop();
        while (st[1].size() > 0) {
            st[0].push(st[1].top());
            st[1].pop();
        }
        return result;
    }
    
    int peek() {
        int result;
        while (st[0].size() > 0) {
            st[1].push(st[0].top());
            st[0].pop();
        }
        result = st[1].top();
        while (st[1].size() > 0) {
            st[0].push(st[1].top());
            st[1].pop();
        }
        return result;    
    }
    
    bool empty() {
        if (st[0].size() > 0) {
            return 0;
        }
        return 1;
    }
private:
    int st_num = 0;
    vector<stack<int>> st;
    
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

