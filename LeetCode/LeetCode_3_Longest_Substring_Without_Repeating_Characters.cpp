/*
    Given a string s, find the length of the longest 
    substring without repeating characters.
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int lengthOfLongestSubstring(string s) {
    int ans = INT_MIN ;
    int ct = 0 ;
    unordered_map<char,int> mp ;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++ ;
        if (i == 0) ct++ ;
        // ct++ ;
        else {
            if(s[i] != s[i-1] && (mp[s[i]] == 1)) {
                ct++ ;
            }else {
                ct = 0 ;
                mp[s[i]] = 0 ;
            }
        }
        ans = max(ans, ct) ;
    }
    return ans ;
}

int main()
{
    string s ;
    cin >> s ;
    cout << lengthOfLongestSubstring(s) ;
    return 0 ;
}