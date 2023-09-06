/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    static std::string longestCommonPrefix(std::vector<std::string> &strs) {
        std::string prefix;
        bool stillPrefix = true;
        int i = 0;

        std::sort(strs.begin(), strs.end(),
                  [](std::string a, std::string b)
                  -> bool {return a > b;}
                  );
        while (stillPrefix && i < strs[0].size()) {
            for (int j = 1; j < strs.size(); ++j) {
                if (!(strs[0].substr(0, i+1) == strs[j].substr(0, i+1))) {
                    stillPrefix = false;
                    break;
                }
            }
            if(!stillPrefix)
                break;
            prefix += strs[0][i];
            ++i;
        }
        return prefix;
    }
};

int main() {
    {
        std::vector<std::string> str = {"1", "2", "3", "4"};
        std::cout << Solution::longestCommonPrefix(str) << std::endl;
    }
    {
        std::vector<std::string> str = {"flower","flower","flower","flower"};
        std::cout << Solution::longestCommonPrefix(str) << std::endl;
    }
    {
        std::vector<std::string> str = {"a"};
        std::cout << Solution::longestCommonPrefix(str) << std::endl;
    }
    return 0;
}