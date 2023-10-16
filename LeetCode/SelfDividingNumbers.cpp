#include "vector"

class Solution {
public:
    static std::vector<int> selfDividingNumbers(short left, short right) {
        std::vector<int> arr;
        short num = 0;
        short tmp = 0;
        for(;left <= right; ++left)
        {
            num = left;
            tmp = left;
            while(tmp)
            {
                if(tmp%10 == 0)
                    break;
                if(num % (tmp % 10) != 0)
                    break;
                tmp /= 10;
            }
            if(!tmp)
                arr.push_back(left);
        }
        return arr;
    }
};