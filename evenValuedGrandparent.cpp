#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

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
    int ans = 0;
    void inorder(TreeNode *root){
        if(root == NULL) return;
        inorder(root->left);
        if(root != NULL && root->val%2 == 0){
            if(root->left != NULL){
                if(root->left->left != NULL) ans += root->left->left->val;
                if(root->left->right != NULL) ans += root->left->right->val;
            }
            if(root->right != NULL){
                if(root->right->left != NULL) ans += root->right->left->val;
                if(root->right->right != NULL) ans += root->right->right->val;
            }
        }
        inorder(root->right);
    }
    int sumEvenGrandparent(TreeNode* root) {
        if(root == NULL) return ans;
        inorder(root);
        return ans;
    }
};