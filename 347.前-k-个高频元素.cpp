/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include "headers.h"
// @lc code=start
class Solution {
    static bool cmp(pair<int, int> &m, pair<int, int> &n) {
        return m.second > n.second;
    }

  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)>
            pq(cmp);
        unordered_map<int, int> map;
        int n = nums.size();
        for (auto it : nums) {
            map[it]++;
        }
        for (auto it : map) {
            if (pq.size() < k) {
                pq.push(make_pair(it.first, it.second));

            } else if (it.second > pq.top().second) {
                pq.pop();
                pq.push(make_pair(it.first, it.second));
            }
        }
        vector<int> ans;
        n = pq.size();
        for (int i = 0; i < k && i < n; i++) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end
int main() {
    vector<int> nums = {5, 3, 1, 1, 1, 3, 73, 1};
    Solution s;
    vector<int> ans = s.topKFrequent(nums, 2);
    for (auto it : ans) {
        cout << it << " ";
    }
    return 0;
}