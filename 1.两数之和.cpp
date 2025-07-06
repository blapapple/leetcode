/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include "headers.h"

// @lc code=start
class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            auto it = map.find(target - nums[i]);
            if (it != map.end()) {
                return {it->second, i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    Solution s;
    vector<int> ret = s.twoSum(nums, 7);
    cout << "success";
    return 0;
}