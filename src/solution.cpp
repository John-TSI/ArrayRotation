#include"../inc/solution.hpp"


void Solution::rotate(std::vector<int>& nums, int k)
{
    if(!k){ return; }
    // an n-element array rotation by k elements can be implemented by first reversing the entire array,
    // then reversing in turn the first k elements and the remaining n-k elements
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + (k % nums.size()) );
    std::reverse(nums.begin() + (k % nums.size()), nums.end() );
}