#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

unordered_map <char, int> HSH(string & str) {
    unordered_map<char,int> ans ;
    for (auto & ch : str) ans[ch]++ ;
    return ans ;
}
vector<int> findAnagrams(string s, string p) {
    int n = s.length();
    int n2 = p.length() ;
    if(n < n2) return {} ;
    if (s == p) return {0} ;
    vector<int> ans ;
    unordered_map<char, int> h1 = HSH(p) ;
    for(int i = 0 ; i <= n - n2 ; i++) {
        string temp = s.substr(i, n2) ;
        unordered_map<char, int> h2 = HSH(temp) ;
        if (h1 == h2) ans.push_back(i) ;
        h2.clear() ;
    }
    return ans ;
}

int main()
{
    string s, p ;
    cin >> s >> p ;
    for (auto & i : findAnagrams(s,p)) {
        cout << i << " " ;
    }
    return 0 ;
}