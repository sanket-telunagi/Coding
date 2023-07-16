#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int longestValidSubstring(string word, vector<string>& forbidden) {
    int n = word.length() ;
    unordered_map<string, int> mp ;
    for(auto & it : forbidden) mp[it]++ ;

    int l = 0 , r = 0 , res = 0  ;

    for (int i = 0; i < n; i++)
    {
        string temp = word.substr(l, r - l + 1) ;
        cout << temp << endl ;
        if (mp.find(temp) != mp.end()) {
            while (mp.find(temp) != mp.end()) {
                l++ ;
                
                temp = word.substr(l, r - l + 1) ;
                cout << temp << endl ;
            }
        }
        res = max(res, r - l + 1) ;
        r++ ;
    }

    return res ;
    
}

int main()
{
    string s ;
    cin >> s ;
    int n ;
    cin >> n ;
    vector<string> forbidden(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> forbidden[i] ;
    }
    cout << longestValidSubstring(s, forbidden) << endl ;
    return 0 ;
}