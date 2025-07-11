/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include "headers.h"
// @lc code=start
class Solution {
  public:
    int jump(vector<int> &nums) {
        int end = 0, maxLoc = 0, ans = 0, n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            // if (maxLoc >= i) {
            maxLoc = max(maxLoc, i + nums[i]);
            if (i == end) {
                end = maxLoc;
                ans++;
            }
            // }
        }
        return ans;
    }
};
// @lc code=end
