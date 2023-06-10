/*
    Given an integer array nums, 
    return all the triplets [nums[i], nums[j], nums[k]] 
    such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
    Notice that the solution set must not contain duplicate triplets
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int binSearch(vector<int> & nums, int s, int target) {
    int e = nums.size() - 1 ;
    while (e - s > 1)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] < target) {
            s = mid + 1 ;
        }else {
            e = mid;
        }
    }
    return nums[e] == target ? e : -1 ;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end()) ;
    vector<vector<int>> trips;
    set<vector<int>> buffer ;
    int p1 = 0 , p2, p3 ;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        p1 = i ;
        for (int j = p1 + 1; j < nums.size() - 1; j++)
        {  
            p2 = j ;
            int target = -1 * (nums[p1] + nums[p2]) ;
            int ans = binSearch(nums, p2, target) ;
            if (ans != -1) {
                buffer.insert({nums[p1],nums[p2],nums[ans]}) ;
            }
            else {
                break ;
            }
        }
    }
    for (auto & it : buffer) {
        trips.push_back({it[0], it[1], it[2]}) ;
    }
    buffer.clear() ;
    return trips ;   
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    for (auto it : threeSum(nums)) {
        cout << it [0] << " " << it [1] << " " << it[2] << endl ;
    };
    
    return 0 ;
}