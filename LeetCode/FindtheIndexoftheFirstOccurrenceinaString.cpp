#include <iostream>
#include "vector"
#include "math.h"
/*Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.*/

class Solution {
public:
    static int strStr(std::string haystack, std::string needle) {
        int index = -1;
        bool isSubstr = true;
        if(haystack.size() < needle.size())
            return index;
        for(size_t i = 0; i < haystack.size(); ++i)
        {
            if(haystack[i] == needle[0] && needle.size() <= haystack.size() )
            {
                isSubstr = true;
                for(size_t j = 1; j < needle.size(); ++j)
                {
                    if(haystack[i + j] != needle[j]) {
                        isSubstr = false;
                        break;
                    }
                }
                if(isSubstr)
                    return i;
            }
        }
        return index;
    }
};

int main()
{
    std::cout << Solution::strStr("mississippi", "issip") << std::endl;
    return 0;
}