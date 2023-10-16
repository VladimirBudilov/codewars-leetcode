#include <iostream>
#include "vector"

/*A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.

Given an integer n, return true if n is a perfect number, otherwise return false.*/

class Solution {
public:
    static bool checkPerfectNumber(int num) {
        int sum = 0;
        for(int i = 1; i < num; ++i) {
            if (num % i == 0)
                sum += i;
        }
        return num == sum;
    }
};

int main()
{
    if(Solution::checkPerfectNumber(28))
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    return 0;
}