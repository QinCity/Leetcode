/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        for (int i = 0; i < tokens.size(); i++) {
            int sum = 0;
            if (tokens[i][0] == '+') {
                sum = num.top();
                num.pop();
                sum += num.top();
                num.pop();
                num.push(sum);
            }
            else if (tokens[i].size() <= 1 && tokens[i][0] == '-') {
                sum = num.top();
                num.pop();
                sum = num.top() - sum;
                num.pop();
                num.push(sum);
            }
            else if (tokens[i][0] == '*') {
                sum = num.top();
                num.pop();
                sum *= num.top();
                num.pop();
                num.push(sum);
            }
            else if (tokens[i][0] == '/') {
                sum = num.top();
                num.pop();
                sum = num.top() / sum;
                num.pop();
                num.push(sum);
            }
            else {
                if (tokens[i][0] == '-') {
                    for (int j = 1; j < tokens[i].size(); j++) {
                        sum *= 10;
                        sum += tokens[i][j] - '0';
                    }
                    sum = -sum;
                    num.push(sum);
                }    
                else {
                    for (int j = 0; j < tokens[i].size(); j++) {
                        sum *= 10;
                        sum += tokens[i][j] - '0';
                    }
                    num.push(sum); 
                }
                
            }

        } 
        return num.top();
    }
};
// @lc code=end

