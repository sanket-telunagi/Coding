# include <iostream>
# include <vector>

void printG(vector<vector<int>> & G) {
    int i = 0 ;
    for (auto & it : G) {
        cout << i << " : " ;
        for (auto & i : it ) {
            cout << i << " " ;
        }
        cout << endl ;
        i++ ;
    }
}