#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// int climbStairs(int n) {
//     int ct = 0 ;
//     if (n <= 0) return 0;
//     ct = climbStairs(n-1) + 1;
//     if (n - 1 > 1) {
//         ct = climbStairs(n - 2) + 1;
//     }
//     return ct ;
// }

int climbStairs(int n , vector<int> & dp){
    if (n == 0) return 0 ;
    if (dp[n] != -1) return dp[n] ;
    int step = INT_MAX ;
    step = min(step,climbStairs(n - 1, dp) + 1) ;
    if(n > 1) {
        step = min(step, climbStairs(n - 2, dp) + 1) ;
    }
    return dp[n] = step ;
}

int climbStairs(int n , int * dp){
    if (n == 0 || n == 1) return 1;
    if (dp[n] != -1) return dp[n] ;
    int step = INT_MAX ;
    step = min(step,climbStairs(n - 1, dp) + 1) ;

    if(n > 1) {
        step = min(step, climbStairs(n - 2, dp) + 1) ;
    }
    return dp[n] = step ;
}

int main()
{
    int n ;
    cin >> n ;
    // vector<int> dp(n+1,-1) ;
    int dp [n+1] ;
    memset(dp, -1 , sizeof(dp)) ;

    int ans = climbStairs(n,dp) ;
    cout << ans ;
    return 0 ;
}