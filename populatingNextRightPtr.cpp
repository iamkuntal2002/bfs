#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution1 {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node*> qu;
        qu.push(root);
        while(!qu.empty()){
            int size = qu.size();
            for(int i =0;i<size;i++){
                Node *curr = qu.front();
                qu.pop();
                if(curr->left) qu.push(curr->left);
                if(curr->right) qu.push(curr->right);
                if(i == size-1){
                    curr->next = NULL;
                    break;
                }
                Node *currnext = qu.front();
                curr->next = currnext;
            }
        }
        return root;
    }
};



class Solution2 {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node*> qu;
        qu.push(root);
        while(!qu.empty()){
            int size = qu.size();
            for(int i =0;i<size;i++){
                Node *curr = qu.front();
                qu.pop();
                if(curr->left) qu.push(curr->left);
                if(curr->right) qu.push(curr->right);
                if(i == size-1){
                    curr->next = NULL;
                    break;
                }
                Node *currnext = qu.front();
                curr->next = currnext;
            }
        }
        return root;
    }
};