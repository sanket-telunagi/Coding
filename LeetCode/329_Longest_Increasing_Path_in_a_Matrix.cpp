/*
    Given a m x n matrix return the longest increasing path 
    in matrix 
    From each cell you can either move up, down, right, left
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;


void DFS(int i , int j,vector<vector<int>> & matrix,int initial, int & ct) {
    int m = matrix.size() ;
    int n = matrix[0].size() ;

    if ( i < 0 || j < 0 || i >= n || j >= m) return;
    if (matrix[i][j] <= initial) return ;

    if (matrix[i][j] > initial) {
        initial = matrix[i][j] ;
        ct++ ;
        // cout << initial << " " ;

        // Go up
        DFS(i , j-1, matrix, initial, ct) ;

        // Go down
        DFS(i , j+1, matrix, initial, ct) ;

        // Go right
        DFS(i+1 , j, matrix, initial, ct) ;

        // Go left
        DFS(i-1 , j, matrix, initial, ct ) ;
        // cout << endl ;
    }

}

int longestIncreasingPath(vector<vector<int>> & matrix) {
    // int ct = 0 ;
    int ans = 0 ;
    for (int i = 0; i < matrix.size(); i++)
    {
        int len ;
        for (int j = 0; j < matrix[i].size(); j++)
        {
            DFS(i,j,matrix, 0, len) ;
            ans = max(ans, *len) ;
        }
  
    }
    
    return ans ;
}

int main()
{
    int n , m ;
    cin >> n >> m ;
    vector<vector<int>> matrix ;
    for (int i = 0; i < m; i++)
    {
        vector<int> temp ;
        for (int j = 0; j < n; j++)
        {
            int x ;
            cin >> x ;
            temp.push_back(x) ;
        }
        matrix.push_back(temp) ;
    }
    cout << longestIncreasingPath(matrix) ;
    return 0 ;
}