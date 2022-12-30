#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int climbStairs(int n) {
    int ct = 0 ;
    if (n <= 0) return 0;
    ct = climbStairs(n-1) + 1;
    if (n - 1 > 1) {
        ct = climbStairs(n - 2) + 1;
    }
    return ct ;
}

int main()
{
    int n ;
    cin >> n ;
    int ans = climbStairs(n) ;
    cout << ans ;
    return 0 ;
}