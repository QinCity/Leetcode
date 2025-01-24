/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
    bool x_is_used[9][9];
    bool y_is_used[9][9];
    bool z_is_used[9][9];
    vector<pair<int, int>> data;
    void tryPlace(vector<vector<char>>& board) {
        for (auto it = data.begin(); it != data.end(); it++) {
            cout << it-> first << it->second << " ";
        }
        cout << endl;
        for (auto it = data.begin(); it != data.end(); ) {
            vector<char> candidate;
            for (int i = 0; i < 9; i++) {
                if (x_is_used[it->first][i] == 0 && y_is_used[it->second][i] == 0 && z_is_used[it->first / 3 + it->second / 3 * 3][i] == 0)
                    candidate.push_back(i);
            }
            if (candidate.size() == 1) {
                board[it->first][it->second] = candidate.back() + '1';
                it = data.erase(it); // 删除
                x_is_used[it->first][candidate.back()] = 1;
                y_is_used[it->second][candidate.back()] = 1;
                z_is_used[it->first / 3 + it->second / 3 * 3][candidate.back()] = 1;
            } else {
                ++it;
            }   
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.'){
                    x_is_used[i][board[i][j] - '1'] = 1;
                    y_is_used[j][board[i][j] - '1'] = 1;
                    z_is_used[i / 3 + j / 3 * 3][board[i][j] - '1'] = 1;
                }
                else {
                    data.emplace_back(i,j);
                }
            }
            
        }
        while (!data.empty())
            tryPlace(board);
    }
};
// @lc code=end

