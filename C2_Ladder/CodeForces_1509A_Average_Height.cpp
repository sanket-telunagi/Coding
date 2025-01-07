#include<bits/stdc++.h>
using namespace std ;
int main() {
    int t; 
    cin >> t ;
    while (t--)
    {
        int n ; 
        cin >> n ;
        stack<int> oddnums ;
        stack<int> evennums;
        cout << n << endl;

        for (int i = 0; i < n; i++)
        {
            int num ;
            cin >> num ;
            
            if (num % 2 == 0) evennums.push(num) ;
            else oddnums.push(num);

            cout << num << " " << evennums.top() << " " << oddnums.top() << endl ;
        }

        

        while (!oddnums.empty() && !evennums.empty())
        {
            if(!oddnums.empty()) {
                cout << oddnums.top() << " " ;
                oddnums.pop();
            }

            if(!evennums.empty()) {
                cout << evennums.top() << " ";
                evennums.pop();
            }
        }
        
        cout << endl ;
    }
    
    return 0 ;
}