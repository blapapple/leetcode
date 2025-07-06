#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class Solution {
    public:
        int minCut(std::string s) {
            int n = s.size();
            std::vector<std::vector<int>> g(n, std::vector<int>(n, true));

            
        }
    };

int main() {
    std::fstream file("./input.txt");
    if(file.is_open()){
        std::string str;
        while (std::getline(file, str)){
            Solution sol;
            std::cout << sol.minCut(str) << std::endl;
        }
    }
    file.close();
    return 0;
}