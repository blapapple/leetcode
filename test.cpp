
#include "headers.h"

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
        for (int i = 0; i < n; i++) {
            if (pq.size() < k && map.count(nums[i]) == 0) {
                map[nums[i]]++;
                pq.push(make_pair(nums[i], map[nums[i]]));
                continue;
            }
            map[nums[i]]++;
            if (map[nums[i]] > pq.top().second) {
                pq.pop();
                pq.push(make_pair(nums[i], map[nums[i]]));
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

int main() {
    vector<int> nums = {5, 3, 1, 1, 1, 3, 73, 1};
    Solution s;
    vector<int> ans = s.topKFrequent(nums, 1);
    for (auto it : ans) {
        cout << it << " ";
    }
    return 0;
}