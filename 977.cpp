#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

class Solution {
    public:
        std::vector<int> sol(int target, std::vector<int>& nums){
            if(nums.size() == 0) return {};
            int head = 0, tail = nums.size() - 1;
            int ptr = nums.size() - 1;
            std::vector<int> ret(nums.size(), 1);
            while (head <= tail){
            if (std::abs(nums[head]) > std::abs(nums[tail])){
                ret[ptr--] = nums[head] * nums[head];
                head++;
            }
            else if (std::abs(nums[head]) < std::abs(nums[tail])){
                ret[ptr--] = nums[tail] * nums[tail];
                tail--;
            }
            else{
                ret[ptr--] = nums[head] * nums[head];
                head++;
            }
            }
            return ret;
        }
};

int main() {
    std::ifstream file("./input.txt");
    if(file.is_open()) {
        std::string str;
        std::vector<int> nums;
        int target;
        std::getline(file, str);
        std::stringstream ss(str);
        std::string token;
        while (std::getline(ss, token, ' ')){
            nums.push_back(std::stoi(token));
        }
        std::getline(file, str);
        target = std::stoi(str);
        Solution sol;
        std::vector<int> res = sol.sol(target, nums);
        std::cout << "Result: ";
        for(auto& str : res){
            std::cout << str << " ";
        }
    }
    return 0;
}