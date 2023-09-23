#include <iostream>
#include <climits>

class Solution {
public:
    static int myAtoi(std::string s) {
        long long res = 0;
        int sign = 1;
        auto it = s.begin();
        while(*it == ' ')
            ++it;
        if(*it == '-' || *it == '+') {
            if(*it == '-')
                sign *= -1;
            ++it;
        }
        while(( *it <= '9' && *it >= '0') && it != s.end())
        {
            res = (res * 10) + (*it - '0');
            if(res > INT_MAX) {
                res = sign == 1 ? INT_MAX : res;
                res = (res > static_cast<long long>INT_MAX + 1) && sign == -1 ? INT_MIN : res;
                return static_cast<int>(res);
            }
            ++it;
        }
        res *= sign;
        return static_cast<int>(res);
    }
};
