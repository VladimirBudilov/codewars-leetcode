#include "iostream"
#include "vector"

class Solution {
public:
    static int removeDuplicates(std::vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        std::vector<int> uniq;
        for(auto num : nums)
        {
            if(std::count(uniq.begin(), uniq.end(), num))
                continue;
            uniq.push_back(num);
        }
        return uniq.size();
    }
};



int main()
{
    std::vector<int> arr;
    arr = {1, 2 ,3 ,4 ,5 ,1, 1, 1, 6 ,1 , 2 ,3};
    std::cout << Solution::removeDuplicates(arr) << std::endl;
    return 0;
}