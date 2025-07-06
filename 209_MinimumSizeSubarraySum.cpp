#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

class Solution {
    public:
        int sol(int target, std::vector<int>& nums){
            int ret = INT_MAX;
            int sum = 0;
            int j = 0;
            int tempRet = 0;
            for (int i =0; i < nums.size();){
                while(sum < target && i < nums.size()){
                    sum += nums[i];
                    i++;
                    tempRet++;
                }
                ret = tempRet < ret && sum >= target ? tempRet : ret;
                while(sum >= target && j < i){
                    sum -= nums[j];
                    tempRet--;
                    if (sum >= target){
                        ret = tempRet < ret && sum >= target ? tempRet : ret;
                    }
                    j++;
                }
            }
            return ret != INT_MAX ? ret : 0;
        }
};

int main() {
    std::ifstream file("./input.txt");
    if(file.is_open()) {
        std::string str;
        std::vector<int> nums;
        int target;
        std::getline(file, str);
        target = std::stoi(str);
        std::getline(file, str);
        std::stringstream ss(str);
        std::string token;
        while (std::getline(ss, token, ' ')){
            nums.push_back(std::stoi(token));
        }
        Solution sol;
        int ret = sol.sol(target, nums);
        std::cout << ret ;
    }
    return 0;
}