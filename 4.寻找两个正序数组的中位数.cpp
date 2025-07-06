/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */
#include "headers.h"
// @lc code=start
class Solution {
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        int n = nums1.size(), m = nums2.size();

        int left = -1, right = n;
        while (left + 1 < right) {
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i - 2;
            if (nums1[i] <= nums2[j + 1]) {
                left = i;
            } else {
                right = i;
            }
        }
        int i = left;
        int j = (m + n + 1) / 2 - i - 2;
        int nums1_i = i >= 0 ? nums1[i] : INT_MIN;
        int nums2_j = j >= 0 ? nums2[j] : INT_MIN;
        int nums1_i1 = i + 1 < n ? nums1[i + 1] : INT_MAX;
        int nums2_j1 = j + 1 < m ? nums2[j + 1] : INT_MAX;
        int max1 = max(nums1_i, nums2_j);
        int max2 = min(nums1_i1, nums2_j1);
        return (m + n) % 2 ? max1 : (max1 + max2) / 2.0;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> nums1 = {};
    vector<int> nums2 = {3, 4};
    double ret = s.findMedianSortedArrays(nums1, nums2);
    cout << ret;
    return 0;
}