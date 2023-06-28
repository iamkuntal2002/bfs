#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/check-completeness-of-a-binary-tree/


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
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL) return true;
        queue<TreeNode*> qu;
        qu.push(root);
        while(qu.front() != NULL) {
            TreeNode *node = qu.front();
            qu.pop();
            qu.push(node->left);
            qu.push(node->right);
        }
        while(!qu.empty() && qu.front() == NULL) qu.pop();
        if(qu.empty()) return true;
        return false;
    }
};