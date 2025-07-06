/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include "headers.h"
// @lc code=start
class Solution {
    static int findMin(vector<int> &nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int left = 0, right = nums.size() - 2;
        int ret;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] < nums[nums.size() - 1]) {
                right = mid - 1;
            } else {
                left = mid + 1;
                ret = left;
            }
        }
        return ret;
    }

  public:
    int search(vector<int> &nums, int target) {
        int minIndex = findMin(nums);
        int left, right;
        int n = nums.size() - 1;
        if (minIndex == 0) {
            left = 0;
            right = n - 1;
        } else {
            if (nums[n] < target) {
                left = 0;
                right = minIndex - 1;
            } else {
                left = minIndex;
                right = n;
            }
        }
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return nums[right + 1] == target ? right + 1 : -1;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> nums = {1};
    int ret = s.search(nums, 1);
    cout << ret;
    return 0;
}