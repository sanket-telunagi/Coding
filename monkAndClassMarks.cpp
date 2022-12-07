#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

int main() {
    int t ;
    cin >> t ;
    map<int,multiset<string>> result ;
    while (t--)
    {
        int marks ;
        string names ;
        cin >> names >> marks ;
        result[-1*marks].insert(names) ;  // for setting the elements in decreasing order : negative numbers logic
    }
    // for (auto it = --result.end(); it !=result.begin() ; --it) {
    //     auto &names = (*it).second ;
    //     for(auto name : names){
    //         cout << name << " " << it->first << endl ;
    //     }
    // }
    // auto cur = --result.end() ;
    // while (true)
    // {
    //     auto &names = cur->second ;
    //     for(auto name : names) {
    //         cout << name << " " << cur->first << endl ;
    //     }
    //     if(cur == result.begin()) break;
    //     cur-- ;
    // }

    // & : to not create copies instead get the refernce
    for(auto &student_marks_pair : result){
        auto &names = student_marks_pair.second ;
        for(auto name : names) {
            cout << name << " " << -1 * student_marks_pair.first << endl ;
        }
    }
    
    return 0 ;
}