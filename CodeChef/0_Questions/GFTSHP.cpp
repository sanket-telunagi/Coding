#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int n , p ;
        cin >> n >> p ;
        vector<int> nums(n) ;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i] ;
        }
        sort(nums.begin(), nums.end()) ;
        int i = 0 , ct = 0 ,
            isDis = false ;;
        while (p >= 0 && n > 0)  // loop over all the items provided the ramining money is >= p
        {   
            if (p - nums[i] >= 0) {
                p -= nums[i] ;
                ct++ ;
            } else if (!isDis && (p - nums[i] / 2 >= 0)) {
                p -= nums[i] / 2 ;
                ct++ ;
                isDis != isDis ;
            }
            i++ ;
            n-- ;
        }
        
        cout << ct << endl ;
    }
    return 0 ;
}