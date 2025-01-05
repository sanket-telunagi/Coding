#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tttttttt;
    cin >> tttttttt;
    while (tttttttt--)
    {
        int val;
        cin >> val;
        cout << (100 / gcd(100, val)) << endl;
    }
    return 0;
}