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
        int sol(std::vector<int>& nums, int k){
            int haed = 0;
            int sum = 0;
            int ret = 0;
            std::unordered_map<int, int> map;
            map[0] = 1;
            for(int i = 0; i < nums.size(); i++){
                sum += nums[i];
                if(map.find(sum - k) != map.end()){
                    ret += map[sum - k];
                }
                map[sum]++;
            }
            return ret;
        }
};

int main() {
    std::ifstream file("./input.txt");
    if(file.is_open()) {
        std::string str;
        std::string target;
        std::getline(file, str);
        std::getline(file, target);
        std::stringstream ss(str);
        std::string token;
        std::vector<int> nums;
        while (std::getline(ss, token, ',')){
            nums.push_back(std::stoi(token));
        }   
        Solution sol;
        int ret = sol.sol(nums, std::stoi(target));
        std::cout << ret << " ";
    }
    return 0;
}