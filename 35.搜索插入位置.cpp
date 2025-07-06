/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include "headers.h"
// @lc code=start
class Solution {
  public:
    int searchInsert(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        int ans = nums.size();
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (target <= nums[mid]) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    int target = 6;
    int ret = s.searchInsert(nums, target);
    cout << ret;
    return 0;
}