#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n ;
        cin >> n ;
        int cnt = 0;
        multiset<int> v ;
        multiset<int> :: iterator it1, it2 ;
        for (int i = 0; i < 2*n; i++)
        {
            int x ;
            cin >> x ;
            v.insert(x);
        }
        
        for (it1 = v.begin() ; it1 != v.end() ; ++it1)
        {
            for (it2 = it1; it2 != v.end() ; ++it2) {
                if ((*it1 + *(++it2)) != 0) {
                    v.erase(v.find(*(it1))) ;
                    v.erase(v.find(*(++it2))) ;
                    cnt ++ ;
                }
            }
        }
        if (cnt == n)
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }

    return 0;
}