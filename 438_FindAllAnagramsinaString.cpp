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
        std::vector<int> sol(std::string s, std::string p){
            int windowTail = p.size() - 1;
            int windowHead = 0;
            std::vector<int> ret;
            std::unordered_multiset<char> pSet;
            std::unordered_multiset<char> tmpSet;

            for(auto it : p){
                pSet.insert(it);
            }
            for(int i = windowHead; i < windowTail; i++){
                tmpSet.insert(s[i]);
            }

            while (windowTail < s.size())
            {
                tmpSet.insert(s[windowTail++]);
                if(tmpSet == pSet){
                    ret.push_back(windowHead);
                }
                auto tmpPtr = tmpSet.find(s[windowHead++]);
                tmpSet.erase(tmpPtr);
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
        // std::stringstream ss(str);
        // std::string token;
        // std::vector<int> nums;
        // while (std::getline(ss, token, ',')){
        //     nums.push_back(std::stoi(token));
        // }   
        Solution sol;
        std::vector<int> ret = sol.sol(str, target);
        for(auto it : ret){
            std::cout << it << " ";
        }
    }
    return 0;
}