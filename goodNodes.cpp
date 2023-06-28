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
    int ans = 0;
    void helper(TreeNode *root,int currval){
        if(root == NULL) return;
        if(root->val >= currval) ans++;
        currval = max(currval,root->val);
        helper(root->left,currval);
        helper(root->right,currval);
    }
    int goodNodes(TreeNode* root) {
        if(root == NULL) return ans;
        helper(root,root->val);
        return ans;
    }
};