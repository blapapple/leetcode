/*
 * @lc app=leetcode.cn id=1353 lang=cpp
 *
 * [1353] 最多可以参加的会议数目
 */
#include "headers.h"

// @lc code=start
class Solution {
  public:
    int maxEvents(vector<vector<int>> &events) {
        int maxDay = 0, n = events.size(), ret = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto it : events) {
            maxDay = max(maxDay, it[1]);
        }
        sort(events.begin(), events.end());
        for (int i = 0, j = 0; i <= maxDay; i++) {
            while (j < n && events[j][0] <= i) {
                pq.emplace(events[j++][1]);
            }

            while (!pq.empty() && pq.top() < i) {
                pq.pop();
            }

            if (!pq.empty() && pq.top() >= i) {
                pq.pop();
                ret++;
            }
        }
        return ret;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> events = {{1, 2}, {2, 3}, {3, 4}, {1, 2}};
    Solution s;
    int ret = s.maxEvents(events);
    cout << ret;
    return 0;
}