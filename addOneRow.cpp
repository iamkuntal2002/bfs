#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/add-one-row-to-tree

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
    void helper(TreeNode *root,int val,int depth,int currdepth){
        if(root == NULL) return;
        if(currdepth == depth-1){
            TreeNode * node1 = new TreeNode(val);
            TreeNode *left = root->left;
            root->left = node1;
            node1->left = left;
            TreeNode *node2 = new TreeNode(val);
            TreeNode *right = root->right;
            root->right = node2;
            node2->right = right;
            return;
        }
        else {
            helper(root->left,val,depth,currdepth+1);
            helper(root->right,val,depth,currdepth+1);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == NULL) return NULL;
        if(depth == 0 || depth == 1){
            TreeNode *node = new TreeNode(val);
            node->left = root;
            return node;
        }
        helper(root,val,depth,1);
        return root;
    }
};