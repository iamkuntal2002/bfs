#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
    int helper(TreeNode *root,int currval){
        if(root == NULL) return 0;
        int res = 0;
        res = (currval<=root->val) ? 1 : 0;
        currval = max(root->val,currval);
        res += helper(root->left,currval);
        res += helper(root->right,currval);
        return res;
    }
    int goodNodes(TreeNode* root) {
        return helper(root,root->val);    
    }
};