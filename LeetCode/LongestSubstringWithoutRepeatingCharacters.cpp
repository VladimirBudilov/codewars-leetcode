#include <string>
#include <list>
#include <iostream>

/*Given a string s, find the length of the longest
substring
 without repeating characters.*/



class Solution {
public:
    static int lengthOfLongestSubstring(std::string s) {
        std::string current;
        std::string maxSizeStr;
        for (int i = 0, j = 0; j < s.size(); ++i) {
            if (i == s.size()) {
                j++;
                i = j;
                maxSizeStr = current.size() > maxSizeStr.size() ? current : maxSizeStr;
                continue;
            }
            if (std::count(current.begin(), current.end(), s[i])) {
                maxSizeStr = current.size() > maxSizeStr.size() ? current : maxSizeStr;
                current.clear();
                j++;
                i = j - 1;
                continue;
            } else {
                current += s[i];
            }
        }
        return maxSizeStr.size();
    }
};


int main() {
    {
        std::string s = "biidygc";
        std::cout << Solution::lengthOfLongestSubstring(s) << std::endl;
    }
    {
        std::string s = "jbpnbwwd";
        std::cout << Solution::lengthOfLongestSubstring(s) << std::endl;
    }
    {
        std::string s = "aab";
        std::cout << Solution::lengthOfLongestSubstring(s) << std::endl;
    }
    return 0;
}