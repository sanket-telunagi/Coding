#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

struct Node{
    int val ;
    Node * left ;
    Node * right ;
} ;


unordered_map<int, vector<int>> g ;

void inorder (Node * root, unordered_map<int, vector<int>> & mp){
    if (root == NULL) return ;
    cout << root->val << endl ;

    // Node * n1 = root ;
    int v = root->left->val ;
    g[root->val].push_back(root->left->val) ;
    v = root->right->val;
    g[root->val].push_back(v) ;

    inorder(root->left, mp) ;
    inorder(root->right, mp) ;
    // mp[root->val].push_back(root->right->val) ;
}

Node * newNode(int val) {
    Node * root = (Node *) malloc(sizeof(Node));
    root->val = val ;
    root->left = nullptr ;
    root->right = nullptr ;
    return root ;
}

int main()
{
    

    Node * root = newNode(3);
    
    root->left = newNode(5) ;
    root->left->left = newNode(6) ;
    root->left->right = newNode(2) ;
    root->left->right->left = newNode(7) ;
    root->left->right->right = newNode(4) ;

    root->right = newNode(1) ;
    root->right->left = newNode(0) ;
    root->right->right = newNode(8) ;

    unordered_map<int, vector<int>> mp ;
    inorder(root, mp) ;

    for (auto & it : g) {
        cout << it.first << " : " ;
        for (auto i : it.second) {
            cout << i << ' ' ;
        }
        cout << endl ;
    }

    return 0 ;
}