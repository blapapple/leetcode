/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

#include "headers.h"
// @lc code=start
class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<int> stk;
        vector<int> ret = vector<int>(temperatures.size(), 0);
        stk.push(0);
        for (int i = 1; i < temperatures.size(); i++) {
            if (temperatures[i] > temperatures[stk.top()]) {
                while (!stk.empty() &&
                       temperatures[i] > temperatures[stk.top()]) {
                    ret[stk.top()] = i - stk.top();
                    stk.pop();
                }
            }
            stk.push(i);
        }
        return ret;
    }
};
// @lc code=end

int main() {
    vector<int> tempertures = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution s;
    vector<int> ret = s.dailyTemperatures(tempertures);
    for (auto it : ret) {
        cout << it << ", ";
    }
    return 0;
}