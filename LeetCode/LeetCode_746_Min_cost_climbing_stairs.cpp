#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int climb(vector<int> & nums, int i) {
    if (i >= nums.size()) return 0 ;

    int cost = INT_MAX ;

    // jumped one step 
    if (i + 1 < nums.size())
    cost = min(cost, climb(nums, i + 1) + nums[i]) ;

    if (i + 2 < nums.size())
    cost = min(cost, climb(nums, i + 2) + nums[i]) ;

    return cost ;
}

int minCostClimbingStairs(vector<int>& cost) {
     return climb(cost, 1) ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> cost(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i] ;
    }

    cout << minCostClimbingStairs(cost) ;
    return 0 ;
}