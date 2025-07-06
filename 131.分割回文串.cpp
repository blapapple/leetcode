/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文
 */

#include "headers.h"

// @lc code=start
class Solution {

    static bool isHui(const string &str, int head, int tail) {
        if (head == tail) {
            return true;
        }
        for (int i = head, j = tail; i <= (head + tail) / 2; i++, j--) {
            if (str[i] != str[j]) {
                return false;
            }
        }
        return true;
    }

  public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> nowStr;
        auto dfs = [&](this auto &&dfs, int head) {
            if (head >= s.size()) {
                ret.emplace_back(nowStr);
                return;
            }
            for (int i = head; i < s.size(); i++) {
                if (isHui(s, head, i)) {
                    nowStr.emplace_back(s.substr(head, i - head + 1));
                    dfs(i + 1);
                    nowStr.pop_back();
                }
            }
        };
        dfs(0);
        return ret;
    }
};
// @lc code=end

int main() {
    Solution s;
    string str = "aabab";
    vector<vector<string>> ret = s.partition(str);
    for (auto vec : ret) {
        for (auto str : vec) {
            cout << str << endl;
        }
    }
    return 0;
}