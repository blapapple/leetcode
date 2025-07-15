/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include "headers.h"
// @lc code=start
class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        unordered_map<int, int> map;
        sort(coins.begin(), coins.end());
        int maxnum = amount + 1;
        auto dp = [&](this auto &&dp, int left) {
            if (left == 0) {
                return 0;
            }
            if (left <= 0) {
                return -1;
            }
            if (map.find(left) != map.end()) {
                return map[left];
            }
            int minn = maxnum;
            for (int i = 0; i < coins.size(); i++) {
                if (left >= coins[i]) {
                    minn = min(minn, dp(left - coins[i]) + 1);
                } else {
                    break;
                }
            }
            map[left] = minn;
            return minn;
        };
        int ans = dp(amount);
        return ans != maxnum ? ans : -1;
    }
};
// @lc code=end
int main() {
    vector<int> coins = {2};
    Solution s;
    cout << s.coinChange(coins, 3);
    return 0;
}