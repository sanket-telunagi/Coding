#include<iostream>
using namespace std; 
int main(){
    // cout<<"Hello LeetCode 3516"<<endl;
    int x, y, z;
    cin>>x>>y>>z;
    cout << (abs(x - z) <= abs(y-z) ? 1 : 2) << endl;
    return 0;
}