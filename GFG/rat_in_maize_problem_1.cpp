#include<bits/stdc++.h>
#include <iostream>
using namespace std ;



void genPaths(vector<int> arr [], vector<string> & ans, vector<vector<int>> & path_hsh,string & path,  int i = 0 , int j = 0){
    if(i < 0 || j < 0 || i >= path_hsh.size() || j >= path_hsh[0].size() || arr[i][j] == 0) return ;
    if(i == path_hsh.size() - 1 && j == path_hsh.size() - 1) {
        ans.push_back(path) ;
        return ;
    }
    if(path_hsh[i][j] == 1) {
        return ;
    }
    path_hsh[i][j] = 1 ;

    // move up
    path.push_back('U') ;
    genPaths(arr, ans, path_hsh, path, i - 1, j) ;
    path.pop_back() ;

    // move left
    path.push_back('L') ;
    genPaths(arr, ans, path_hsh, path, i , j-1) ;
    path.pop_back() ;
    
    // move down
    path.push_back('D') ;
    genPaths(arr, ans, path_hsh, path, i + 1, j) ;
    path.pop_back() ;


    // move right
    path.push_back('R') ;
    genPaths(arr, ans, path_hsh, path, i , j+1) ;
    path.pop_back() ;

}

int main()
{
    int n ;
    cin >> n ;
    vector<int> maize[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x ;
            cin >> x ;
            maize[i].push_back(x) ;
        }
        
    }
    
    vector<string> ans ;
    vector<vector<int>> path(n,vector<int> (n,0)) ;
    string empty = "" ;
    genPaths(maize,ans,path, empty) ;

    for(auto it : path) {
        for(auto i : it) {
            cout << i << " " ;
        }
        cout << endl ;
    }

    for(auto it : ans){
        cout << it << endl ;
    }


    return 0 ;
}