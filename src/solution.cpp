#include"../inc/solution.hpp"


void Solution::rotate(std::vector<int>& nums, int k)
{
    int size = nums.size(); k %= size;
    if(!k){ return; }

    // --- solution one : std::reverse ---
    // an n-element array rotation by k elements can be implemented by first reversing the entire array,
    // then reversing in turn the first k elements and the remaining n-k elements
/*     
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + (k % size) );
    std::reverse(nums.begin() + (k % size), nums.end() ); 
 */


    // --- solution two : cyclic permutation ---
    int e{0}, tmp{nums[e]};  // e: 'element', tmp: 'temporary'

    if(size % k)  // if rotation parameter k is not a factor of the vector length
    {
        // iterate repeatedly through nums, cycling each kth element; requires ${size} swaps
        for(int swap{0}; swap<size; ++swap){ std::swap(tmp, nums[(e+k)%size]); e+=k; }
    }
    else  // k is a factor of the vector length --> after size/k swaps we arrive back at a previously visited element
    {
        for(int cycle{0}; cycle<k; ++cycle)  // there are k distinct cycles of length size/k to perform
        {
            for(int swap{0}; swap<(size/k); ++swap){ std::swap(tmp, nums[(e+k)%size]); e+=k; }
            e = (e % size)+1; tmp = nums[e];  // after each cycle, shift the start element to prepare for next cycle
        }
    }
}