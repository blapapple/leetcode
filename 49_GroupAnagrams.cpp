#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>

class Solution {
    public:
        std::vector<std::vector<std::string>> sol(std::vector<std::string> &strs){
            std::unordered_map<std::string, std::vector<std::string>> map;
            std::vector<std::vector<std::string>> ret;
            for(auto str : strs){
                std::string tmp = str;
                std::sort(tmp.begin(), tmp.end());
                map[tmp].push_back(str);
            }
            for(auto it = map.begin(); it != map.end(); it++){
                ret.push_back(it->second);
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
        std::vector<std::string> strs;
        while (std::getline(ss, token, ' ')){
            strs.push_back(token);
        }   
        Solution sol;
        std::vector<std::vector<std::string>> ret = sol.sol(strs);
        for(auto vec : ret){
            for(auto str : vec){
                std::cout << str << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}