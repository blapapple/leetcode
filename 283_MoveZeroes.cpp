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
        std::vector<int> sol(std::vector<int> &nums){
            int slow =0, fast = 0;
            int zero_count = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[fast] == 0){
                    fast++;
                    zero_count++;
                }
                else{
                    nums[slow++] = nums[fast++];
                }
            }
            for(int i = 0; i < zero_count; i++){
                nums[slow++] = 0;
            }
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
        while (std::getline(ss, token, ' ')){
            nums.push_back(std::stoi(token));
        }   
        Solution sol;
        std::vector<int> ret = sol.sol(nums);
        for(auto val : ret){
            std::cout << val << " ";
        }
    }
    return 0;
}