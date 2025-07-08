/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */
#include "headers.h"
// @lc code=start
class Solution {

  public:
    string decodeString(string s) {
        string ret;
        stack<string> strStk;
        stack<int> intStk;
        string str;
        int multi = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                multi = multi * 10 + s[i] - '0';
            } else if (s[i] == '[') {
                intStk.push(multi);
                strStk.push(str);
                multi = 0;
                str.clear();
            } else if (s[i] == ']') {
                string temp = "";
                int curmul = intStk.top();
                intStk.pop();
                while (curmul--) {
                    temp.append(str);
                }
                ret = strStk.top() + temp;
                strStk.pop();
            } else {
                str.push_back(s[i]);
            }
        }
        return ret;
    }
};
// @lc code=end

int main() {
    Solution sol;
    string ret = sol.decodeString("3[a]2[bc]");
    cout << ret;
    return 0;
}