#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

unordered_map<int,vector<int>> mp ;

void pascalsTrinagle(int numRows, vector<vector<int>> & ans) {
    if(numRows == 1) return 1 ;
}

vector<vector<int>> generate(int numRows) {
        
}

int main()
{
    int n ;
    cin >> n ;

    vector<vector<int>> ans = generate(n) ;

    for(auto it : ans) {
        for(auto i : it) {
            cout << i << " " ;
        }
        cout << endl ;
    }
    return 0 ;
}