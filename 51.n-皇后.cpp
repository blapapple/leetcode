/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include "headers.h"
// @lc code=start
class Solution {

  public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<string> temp = vector<string>(n, string(n, '.'));
        vector<bool> diag_1 =
            vector<bool>(2 * n - 1, false); // (n - 1) + (n - 1) + 1
        vector<bool> diag_2 = vector<bool>(2 * n - 1, false);
        set<int> col;
        auto dfs = [&](this auto &&dfs, int row) {
            if (row >= n) {
                ret.emplace_back(temp);
                return;
            }
            for (int i = 0; i < n; i++) {
                if (col.count(i) == 0 && diag_2[i + row] == false &&
                    diag_1[row - i + n - 1] == false) {
                    col.insert(i);
                    diag_1[row - i + n - 1] = true;
                    diag_2[i + row] = true;
                    temp[row][i] = 'Q';
                    dfs(row + 1);
                    temp[row][i] = '.';
                    diag_1[row - i + n - 1] = false;
                    diag_2[i + row] = false;
                    col.erase(i);
                }
            }
            return;
        };
        dfs(0);
        return ret;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<string>> ret = s.solveNQueens(4);
    for (auto strs : ret) {
        for (auto str : strs) {
            cout << str << endl;
        }
        cout << endl;
    }
    return 0;
}