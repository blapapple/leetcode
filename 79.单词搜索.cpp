
/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool exist(vector<vector<char>> &board, string word) {
        vector<vector<bool>> flags;
        string nowWord;
        bool ret = false;
        auto dfs = [&](this auto &&dfs, int nowLen, int x, int y) {
            if (ret == true) {
                return;
            }
            if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) {
                return;
            }
            if (nowWord != word.substr(0, nowWord.length())) {
                return;
            }
            if (nowLen == word.size()) {
                ret = true;
                return;
            }

            if (flags[x][y]) {
                return;
            }
            nowWord.append(board[x][y]);
            flags[x][y] = true;

            dfs(1, x + 1, y);
            dfs(1, )
        };
    }
};
// @lc code=end

int main() {}