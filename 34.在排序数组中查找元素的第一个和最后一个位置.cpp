/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include "headers.h"
// @lc code=start
class Solution {
  public:
    int lower(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    vector<int> searchRange(vector<int> &nums, int target) {
        int start = lower(nums, target);
        if (start == nums.size() || nums[start] != target) {
            return {-1, -1};
        }
        int end = lower(nums, target + 1) - 1;
        return {start, end};
    }
};
// @lc code=end
int main() {
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> ret = s.searchRange(nums, 8);
    for (auto i : ret) {
        cout << i << ",";
    }
    return 0;
}