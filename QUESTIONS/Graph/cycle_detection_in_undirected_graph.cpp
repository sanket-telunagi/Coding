#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// return true if raph contains loop 

bool dfs(int vertex, int par, bool * vis, unordered_map<int,vector<int>> & mp) {
    
    vis[vertex] = true ;

    bool ans = false ;

    for (auto child : mp[vertex]) {
        if (vis[child] && child == par) continue;
        if (vis[child]) return true ;
        ans |= dfs(child, vertex, vis, mp) ;
    }
    return ans ;
}


bool bfs(int src, int * vis, vector<int>  adj[]) {
    // int n= adj.size() ;


    queue<pair<int,int>> q ;
    q.push({src, -1}) ;

    while (!q.empty()) {
        int node = q.front().first ;
        int par = q.front().second ;
        q.pop() ;
        vis[node] = true ;

        for (auto child : adj[node]) {
            if (!vis[child]) {
                vis[child] = true ;
                q.push({child, node}) ;
            } else if (par != child) return true ;
        }
    }
    return false ;
}

bool detectCycle(int n, vector<int> adj[]) {
    // Write your code here.
    // unordered_map<int, vector<int>> mp ;
    
    // for (int i = 0; i < n; i++)
    // {
    //     mp[adj[i][0]].push_back(adj[i][1]) ;
    //     mp[adj[i][1]].push_back(adj[i][0]) ;
    // }

        int vis[n+1] ;
        for (int i = 0; i <= n; i++)
        {
            if (!vis[i])
            if (bfs(i,vis, adj)) return true ;
        }
        
        return false ;
    // for (auto it : mp) {
    //     cout << it.first << " : " ;
    //     for (auto i : it.second) {
    //         cout << i << " " ;
    //     }
    //     cout << endl ;
    // }

    // bool vis[n + 1] = {0};
    // int par = 0 ;
}

int main()
{
    int n , m ;
    cin >> n >> m ;
    vector<int> adj[m] ;
    for (int i = 0; i < m; i++)
    {
        int x, y ;
        cin >>x >> y ;
        adj[i].push_back(x) ;
        adj[i].push_back(y) ;
    }

    // for (int i = 0 ; i< m ; i++) {
    //     cout << adj[i][0] << adj[i][1] << endl ;
    // }

    cout << detectCycle(m, adj) ;

    
    return 0 ;
}