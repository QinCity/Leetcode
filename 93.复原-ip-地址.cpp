/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
private:
    vector<string> result;
    int port[4];
public:
    void traverse(int pos, int s_begin, string &s) {
        if (pos > 4) {
            return;
        }
        if (pos == 4) {
            if (s.size() == s_begin) {
                string ipAddr;
                for (int i = 0; i < 4; ++i) {
                    ipAddr += to_string(port[i]);
                    if (i != 4 - 1) {
                        ipAddr += ".";
                    }
                }
                result.push_back(move(ipAddr));

            }
                // result.push_back(to_string(port[0]) + '.' + to_string(port[1]) + '.' + to_string(port[2]) + '.' + to_string(port[3]));
            return;
        }
        if (s[s_begin] == '0') {
            port[pos] = 0;
            traverse(pos + 1, s_begin + 1, s);
            return;
        }
        int num = 0;
        for (int i = s_begin; num <= 255 && i < s.size() && i <= s_begin + 2; i++) {
            num = num * 10 + s[i] - '0';
            if (num <= 255) {
                port[pos] = num;
            }
            else {
                return;
            }
            traverse(pos + 1, i + 1, s);
        }
    }    


    vector<string> restoreIpAddresses(string s) {
        traverse(0, 0, s);
        return result;
    }
};
// @lc code=end

