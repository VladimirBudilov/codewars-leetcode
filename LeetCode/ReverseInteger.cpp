#include <cmath>
#include "iostream"

class Solution {
public:
    static int reverse(int x) {
        if(x == 0)
            return 0;
        int sign = 1;
        int res = x;
        int counter = 0;
        long long int cheker = 0;
        while ((res = res/10))
            ++counter;
        if (x < 0)
            sign *= -1;
        while (x) {
            cheker += x%10 * pow(10, counter);
            if( cheker > INT32_MAX || cheker < INT32_MIN)
                return 0;
            res += x%10 * pow(10, counter--);
            x /= 10;
        }
        return sign == 1 && (res < 0) ? res * -1 : res;
    }
};

int main() {
    int x = -222453459;
    int res = Solution::reverse(x);
    std::cout << res << std::endl;
    return 0;
}