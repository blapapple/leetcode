
#include "headers.h"
class Solution {
    static int findPow(int p, vector<int> &nums) {
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (p >= nums[i]) {
                return i;
            }
        }
        return 0;
    }

  public:
    int numSquares(int n) {
        vector<int> nums;
        for (int i = 1; pow(i, 2) <= n; i++) {
            nums.push_back(pow(i, 2));
        }
        unordered_map<int, int> map;
        auto dp = [&](this auto &&dp, int left) -> int {
            int a = findPow(left, nums);
            int minRet = INT_MAX;
            // for (int i = a; i >= 0; i--) {
            if (left == nums[a]) {
                return 1;
            }
            int temp;
            if (map.find(left - nums[a]) != map.end()) {
                temp = map[left - nums[a]] + 1;
            } else {
                temp = dp(left - nums[a]);
                map[left - nums[a]] = temp;
                temp += 1;
            }
            minRet = min(minRet, temp);
            // }

            return minRet;
        };
        return dp(n);
    }
};

int main() {
    Solution s;
    cout << s.numSquares(12);
    return 0;
}