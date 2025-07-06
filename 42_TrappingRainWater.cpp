#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

class Solution {
    public:
        int sol(std::vector<int>& height){
            std::vector<int> preSum(height.size(), 0);
            std::vector<int> sufSum(height.size(), 0);
            preSum[0] = height[0];
            sufSum[height.size() - 1] = height[height.size() - 1];

            int ret = 0;
            for(int i = 1; i < height.size(); i++){
                preSum[i] = std::max(height[i], preSum[i - 1]);
            }
            for(int i = height.size() - 2; i >= 0; i--){
                sufSum[i] = std::max(height[i], sufSum[i + 1]);
            }

            for(int i = 0; i < height.size(); i++){
                int lower = std::min(sufSum[i], preSum[i]);
                int nowHeight = lower - height[i];
                ret += nowHeight;
            }
            return ret;
        }
};

int main() {
    std::ifstream file("./input.txt");
    if(file.is_open()) {
        std::string str;
        int target;
        std::getline(file, str);
        std::stringstream ss(str);
        std::string token;
        std::vector<int> nums;
        while (std::getline(ss, token, ',')){
            nums.push_back(std::stoi(token));
        }   
        Solution sol;
        int ret = sol.sol(nums);
        std::cout << ret << " ";
    }
    return 0;
}