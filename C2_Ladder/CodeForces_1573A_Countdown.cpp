#include<bits/stdc++.h>
using namespace std ;
int main() {
    int t;
    cin >> t; 
    while (t--)
    {
        int n ;
        cin >> n ;
        int count = 0 ;
        string num ; 
        cin >> num ;
        count += num[n-1] - '0' ;
        num.pop_back() ;

        while (num.length() > 0)
        {
            if ((num.back() - '0') != 0) count += ((num.back() - '0') + 1) ;
            num.pop_back() ;
        }
        
        cout << count << endl ;
    }
    
    return 0 ;
}