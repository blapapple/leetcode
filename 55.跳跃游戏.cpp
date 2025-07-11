/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include "headers.h"
// @lc code=start
class Solution {
  public:
    bool canJump(vector<int> &nums) {
        int maxPlace = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i <= maxPlace) {
                maxPlace = max(maxPlace, nums[i] + i);
                if (maxPlace >= nums.size() - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
int main() {
    vector<int> nums = {3, 2, 1, 0, 4};
    Solution s;
    cout << s.canJump(nums);
    return 0;
}