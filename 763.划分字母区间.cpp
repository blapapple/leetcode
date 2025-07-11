/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */
#include "headers.h"
// @lc code=start
class Solution {
  public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> map;
        int n = s.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            map[s[i]] = i;
        }
        int end = 0;
        int len = 0;
        for (int i = 0; i < n; i++) {
            end = max(end, map[s[i]]);
            len++;
            if (i == end) {
                ans.push_back(len);
                len = 0;
            }
        }
        return ans;
    }
};
// @lc code=end
