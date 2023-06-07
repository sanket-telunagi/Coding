#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t;
    while (t--) {
        int n ;
        cin >> n ;


        // TLE
        int res = INT_MIN ;
        int temp = n ;
        int ct = 0 ;
        while (--n)
        {
            if (temp == 0) ct++ ;
            temp &= n ;
            res = max(res, ct) ;
        }
        cout << res + 1 << endl ;
        
    }
    return 0 ;
}