#include<iostream>
#include"../inc/solution.hpp"


void PrintVector(const std::vector<int>& vec)
{
	for(int i : vec){ std::cout << i << '\n'; }
}

int main()
{
	std::vector<int> vec{1,2,3,4,5,6,7,8};
	Solution().rotate(vec,12);  // vec = {5,6,7,8,1,2,3,4}
	PrintVector(vec);
	return 0;
}

