/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include "headers.h"
// @lc code=start
class Solution {
  public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string str;
        auto dfs = [&](this auto &&dfs, int leftNum, int rightNum) {
            if (str.size() == n * 2) {
                ret.emplace_back(str);
                return;
            }
            if (leftNum < n) {
                str.append("(");
                dfs(leftNum + 1, rightNum);
                str.pop_back();
            }
            if (rightNum < leftNum) {
                str.append(")");
                dfs(leftNum, rightNum + 1);
                str.pop_back();
            }
            return;
        };
        dfs(0, 0);
        return ret;
    }
};
// @lc code=end

int main() {
    Solution s;
    int n;
    cin >> n;
    vector<string> ret = s.generateParenthesis(n);
    for (auto str : ret) {
        cout << str << endl;
    }
    return 0;
}