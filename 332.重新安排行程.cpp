/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
private:
    unordered_map<string, map<string, int> > ma;
    vector<string> result;
    bool exist = 0;
    void traverse(int remain, string begin) {

        if (exist == 1)
            return;
        if (remain == 0) {
            exist = 1;
            return;
        }
        for (auto &pos: ma[begin]) {
            if (pos.second > 0) {
                pos.second --;
                result.push_back(pos.first);
                traverse(remain - 1, pos.first);
                if (exist)
                    return;
                result.pop_back();
                pos.second ++;
            }
        }
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto ticket : tickets) {
            ma[ticket[0]][ticket[1]]++;
        }
        result.push_back("JFK");
        traverse(tickets.size(), "JFK");
        return result;    
    
    }
};
// @lc code=end

