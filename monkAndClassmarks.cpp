// Solving hackerEarths monk and class marks problem by sorting

#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

bool cmp(pair<string,int> &a , pair<string,int> &b){
    if (a.second == b.second){
        return a.first < b.first ;
    }
    return a.second > b.second ;
}

int main() {
    int n ;
    cin >> n ;
    vector<pair<string,int>> result(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> result[i].first >> result[i].second ;
    }

    sort(result.begin(),result.end(),cmp) ;
    for (int i = 0; i < n; i++)
    {
        cout << result[i].first << " " << result[i].second << endl ;
    }
    
    
    return 0 ;
}