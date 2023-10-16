#include <iostream>
#include "vector"
#include "math.h"
/*A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.*/

class Solution {
public:
    static bool isPalindrome(std::string s) {
        std::string str;
        for(auto c : s)
        {
            if(isalnum(c))
                str += tolower(c);
        }
        std::string s1 = str.substr(0 , (int) (str.size() / 2));
        int adding = str.size()%2 == 0 ? 0 : 1;
        std::string s2 = str.substr((int) (str.size() / 2) + adding, str.size());
        std::reverse(s2.begin(), s2.end());
        return s1 == s2;
    }
};

int main()
{
    std::cout << Solution::isPalindrome("0P") << std::endl;
    return 0;
}
