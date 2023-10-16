#include <iostream>
#include "vector"
#include "math.h"
/*You are given a positive integer n, that is initially placed on a board. Every day, for 109 days, you perform the following procedure:

For each number x present on the board, find all numbers 1 <= i <= n such that x % i == 1.
Then, place those numbers on the board.
Return the number of distinct integers present on the board after 109 days have elapsed.

Note:

Once a number is placed on the board, it will remain on it until the end.
% stands for the modulo operation. For example, 14 % 3 is 2.*/

class Solution {
public:
    static int distinctIntegers(int n) {
        size_t daysNumber = pow(10, 9);
        int counter = 0;
        for (size_t i = 0; i <= daysNumber; ++i)
        {
        }

        return counter;
    }
};

int main()
{
    std::cout << Solution::distinctIntegers(1) << std::endl;
    return 0;
}