#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    string capitalizeTitle(string title)
    {
        bool changeFlag = 1;
        int len = title.size();
        int wordLen = 0;
        for (int i = 0; i <= len; i++)
        {
            if (title[i] == ' ' || i == len)
            {
                changeFlag = 1;
                if (wordLen <= 2)
                {
                    for (int j = 1; j <= wordLen; j++)
                    {
                        title[i - j] = title[i - j] <= 'Z' ? title[i - j] + 32 : title[i - j];
                    }
                }
                wordLen = 0;
                continue;
            }
            if (changeFlag == 1)
            {
                if (title[i] >= 'a')
                {
                    title[i] = title[i] - 32;
                }
                changeFlag = 0;
                wordLen++;
            }
            else
            {
                if (title[i] <= 'Z')
                {
                    title[i] = title[i] + 32;
                }
                wordLen++;
                changeFlag = 0;
            }
        }
        return title;
    }
};

int main()
{
    string title;
    getline(cin, title);
    Solution solution;
    cout << solution.capitalizeTitle(title);
    return 0;
}