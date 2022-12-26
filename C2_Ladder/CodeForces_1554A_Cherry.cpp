#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t;
    cin >> t ;
    while(t--) {
        int n ;
        cin >> n ;
        // int arr[n] ;
        int lo = 0, hi = INT_MIN ;
        long long ans ;
        for (int i = 0; i < n; i++)
        {
            // cin >> arr[i] ;
            int x ;
            cin >> x ;

            if (x > hi) {
                hi = x ;
            }
            if (x > lo && x < hi) {
                lo = x ;
            }
        }
        if (lo==0) {
            ans = round(pow(hi,n)) ;
            cout << ans << endl ;
        } else {
            ans = lo * 1LL * hi ;
            cout << ans << endl ;
        }
    }
    return 0 ;
}