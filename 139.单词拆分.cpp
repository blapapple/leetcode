/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
#include "headers.h"
// @lc code=start
class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_map<string, int> map;
        vector<int> count(s.size() + 1, -1);
        sort(wordDict.begin(), wordDict.end(),
             [&](string &a, string &b) { return a.size() > b.size(); });
        int n = s.size();
        auto dp = [&](this auto &&dp, int left) -> bool {
            if (count[left] != -1) {
                return count[left];
            }
            if (left == n) {
                return true;
            }
            bool res = false;
            for (auto word : wordDict) {
                if (n - left < word.size()) {
                    continue;
                } else {
                    if (!s.substr(left, word.size()).compare(word)) {
                        bool temp = dp(left + word.size());
                        count[left] = temp;
                        res = temp ? temp : res;
                    }
                }
            }
            return res;
        };
        return dp(0);
    }
};
// @lc code=end
int main() {
    vector<string> wordDict = {"a",         "aa",        "aaa",     "aaaa",
                               "aaaaa",     "aaaaaa",    "aaaaaaa", "aaaaaaaa",
                               "aaaaaaaaa", "aaaaaaaaaa"};
    Solution s;
    cout << s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
                        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
                        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
                        wordDict);
    return 0;
}