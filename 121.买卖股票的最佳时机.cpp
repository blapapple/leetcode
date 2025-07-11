/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include "headers.h"
// @lc code=start
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int ans = 0;
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            ans = max(ans, prices[i] - minPrice);
            if (minPrice > prices[i]) {
                minPrice = prices[i];
            }
        }
        return ans;
    }
};
// @lc code=end
