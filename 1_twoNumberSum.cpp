#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      auto it = map.find(target - nums[i]);
      if (it != map.end()) {
        return {it->second, i};
      }
      map[nums[i]] = i;
    }
    return {};
  }
};

int main() {
  std::ifstream file("./input.txt");
  if (file.is_open()) {
    std::string str;
    std::vector<int> nums;
    int target;
    std::getline(file, str);
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, ' ')) {
      nums.push_back(std::stoi(token));
    }
    std::getline(file, str);
    target = std::stoi(str);
    Solution sol;
    std::vector<int> res = sol.twoSum(nums, target);
    std::cout << "Result: ";
    for (auto& str : res) {
      std::cout << str << " ";
    }
  }
  system("pause");
  return 0;
}