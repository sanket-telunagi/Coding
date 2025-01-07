#include<bits/stdc++.h>
using namespace std ;
int main () {
    int t ;
    cin >> t ;
    while (t--) {
        int n ;
        cin >> n ;
        string s1, s2 ;
        cin >> s1 >> s2 ;
        bool bad = false ;
        for (int i = 0; i < n; i++)
        {
            bad |= s1[i] == '1' and s2[i] == '1';
        }
        if (bad) cout << "NO\n";
        else cout << "YES\n" ;
        
    }
    return 0 ;
}