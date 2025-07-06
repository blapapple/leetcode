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
        std::vector<std::vector<int>> sol(std::vector<int> &nums){
            std::sort(nums.begin(), nums.end());
            std::vector<std::vector<int>> ret;
            for(int i = 0; i < nums.size(); i++){
                if(i > 0 && nums[i] == nums[i - 1]){
                    continue;
                }
                int k = nums.size() - 1;
                int target = -nums[i];
                for(int j = i + 1; j < nums.size() && j != i; j++){
                    if(j > i + 1 && nums[j] == nums[j - 1]){
                        continue;
                    }
                    while(j < k && nums[j] + nums[k] > target){
                        k--;
                    }
                    if(j == k){
                        break;
                    }
                    if(nums[j] + nums[k] == target){
                        std::vector<int> tmp = {nums[i], nums[j], nums[k]};
                        ret.push_back(tmp);
                    }
                }
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
        std::vector<std::vector<int>> ret = sol.sol(nums);
        for(auto vec : ret){
            for(auto val : vec){
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}