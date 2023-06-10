/*
    You are given an integer array nums and an integer target.

    You want to build an expression out of nums by adding one of 
    the symbols '+' and '-' before each integer in nums and then concatenate 
    all the integers.

    For example, if nums = [2, 1], 
    you can add a '+' before 2 and a '-' before 1 and concatenate them 
    to build the expression "+2-1".
    Return the number of different expressions that you can build, 
    which evaluates to target.
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// --- > TLE 
// void genSum(vector<int> & nums, int & target, int & count, int index = 0) {
//     if(index >= nums.size()) {
//         int sum = accumulate(nums.begin(), nums.end(), 0) ;
//         if (sum == target) count++ ;
//         return ;
//     }

//     genSum(nums, target, count, index + 1) ;

//     nums[index] *= (-1) ;
//     genSum(nums, target, count, index + 1) ;
//     nums[index] *= (-1) ;
// }

int genSum(vector<int> & nums, int & target) {
    int ct = 0 ;
    for(int i = 0; i < nums.size(); i++) {
        if(accumulate(nums.begin(), nums.end(), 0) == target) ct++ ;
        nums[i] *= (-1) ;
        if(accumulate(nums.begin(), nums.end(), 0) == target) ct++ ;
        nums[i] *= (-1) ;
    }
    return ct ;
}

int findTargetSumWays(vector<int>& nums, int target) {
    // genSum(nums, target, ans) ;

    return genSum(nums, target) ;
}

int main()
{
    int n , k ;
    cin >> n >> k ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++) cin >> nums[i] ;

    cout << findTargetSumWays(nums, k) ;
    
    return 0 ;
}