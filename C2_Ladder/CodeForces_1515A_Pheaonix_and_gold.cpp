#include <bits/stdc++.h>
using namespace std ;
int main() {
    int t; 
    cin>> t ;
    while (t--)
    {
        int n , x;
        cin>> n >> x ;
        vector<int> nums(n,0) ;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i] ;
        }
        int sum = 0 ;
        for (int i = 0; i < n; i++)
        {
            if (sum + nums[i] == x) {
                swap(nums[i], nums[n-1]) ;
            }
            sum += nums[i] ;
        }
        
        bool willExplod = false ;

        int reSum = 0 ;
        for (int i = 0; i < n; i++)
        {
            reSum += nums[i] ;
            if (reSum == x) willExplod = true ;
        }
        
        if (willExplod) {
            cout << "NO\n" ;
        } else {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
            {
                cout << nums[i] << " " ;
            }
            
            cout << endl ;
        }
    }
    
    return 0 ;
}