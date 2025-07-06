/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include "headers.h"

// @lc code=start
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int head = 0, tail = m * n - 1;
        bool ret = false;
        int mid;
        while (head <= tail) {
            mid = (tail - head) / 2 + head;
            if (matrix[mid / n][mid % n] == target) {
                return true;
            } else if (matrix[mid / n][mid % n] < target) {
                head = mid + 1;
            } else {
                tail = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    bool ret = s.searchMatrix(matrix, 3);
    return 0;
}
