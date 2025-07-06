#include <fstream>
#include <functional>
#include <iostream>
#include <ostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    vector<string> ret;
    if (digits.empty()) return ret;

    const vector<string> groups = {"abc", "def",  "ghi", "jkl",
                                   "mno", "pqrs", "tuv", "wxyz"};

    string s;
    int len = digits.size();

    // C++20 兼容方案
    std::function<void(int, int)> dfs;
    dfs = [&](int pos, int size) {
      if (pos == size) {
        ret.push_back(s);
        return;
      }
      for (char c : groups[digits[pos] - '2']) {
        s.push_back(c);
        dfs(pos + 1, size);
        s.pop_back();
      }
    };

    dfs(0, len);
    return ret;
  }
};

int main() {
  std::ifstream file("input.txt");
  string str;
  getline(file, str);
  Solution solution;
  std::ofstream output("output.txt");
  for (auto i : solution.letterCombinations(str)) {
    output << i << std::endl;
  }
  return 0;
}