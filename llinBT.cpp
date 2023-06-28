#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/linked-list-in-binary-tree

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    bool helper(ListNode *head,TreeNode *root){
        if(head == NULL) return true;
        if(root == NULL) return false;
        if(root->val != head->val) return false;
        return helper(head->next,root->left) || helper(head->next,root->right); 
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == NULL) return false;
        if(head == NULL) return true;
        if(root == NULL && head != NULL) return false;
        if(root != NULL && head == NULL) return true;
        return helper(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }
};