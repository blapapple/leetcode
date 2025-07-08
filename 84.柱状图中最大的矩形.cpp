/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
#include "headers.h"
// @lc code=start
class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        int ans = 0;
        vector<int> a;
        a.push_back(0);
        a.insert(a.end(), heights.begin(), heights.end());
        a.push_back(0);
        stack<int> stk;
        for (int i = 0; i < a.size(); i++) {
            while (!stk.empty() && a[i] < a[stk.top()]) {
                int h = a[stk.top()];
                stk.pop(); // 把这段范围中心pop掉后，找左边界
                int w = i - stk.top() - 1; // i是右边界，不参与计算
                ans = max(ans, h * w);
            }
            stk.push(i);
        }
        return ans;
    }
};
// @lc code=end

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    Solution s;
    int ret = s.largestRectangleArea(heights);
    cout << ret;
    return 0;
}