#include<bits/stdc++.h>
using namespace std ;

vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    vector<string> result ;
    map<string, vector<int>> hash1 , hash2; 


    for(string word : words1) {
        hash1[word] = vector<int> (26,0) ;
        for (char letter : word) {
            hash1[word]['a'-letter] += 1;
        }
    }

    for(string word : words2) {
        hash2[word] = vector<int> (26,0) ;
        for (char letter : word) {
            hash2[word]['a'-letter] += 1;
        }
    }

    for(string word : words1) {
        bool isUniversal = true ;
        for (auto & pr : hash2) {
            string word = pr.first ;
            vector<int> hash = pr.second ;

            for (int i = 0; i < 26; i++)
            {
                if (hash[i] < hash1[word][i]) {
                    isUniversal = false ;
                    break;
                }
            }
            
            if(isUniversal) {
                result.push_back(word);
            }

        }
    }

    return result ;
}
int main() {
    int words1num, words2num ;
    cin >> words1num >> words2num ;

    vector<string> words1, words2 ;
    for (int i = 0; i < words1num; i++)
    {
        string word ;
        cin >> word ;
        // cout << word ;
        words1.push_back(word);
    }

    for (int i = 0; i < words2num; i++)
    {
        string word ;
        cin >> word ;
        words2.push_back(word);
    }
    
    vector<string> result = wordSubsets(words1, words2) ;
    for(string word : words2) {
        cout << word << " " ;
    }
    
    return 0 ;
}