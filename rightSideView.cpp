#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/binary-tree-right-side-view

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> qu;
        qu.push(root);
        if(root == NULL) return res;
        while(!qu.empty()){
            int size = qu.size();
            while(size--){
                TreeNode *curr = qu.front();
                qu.pop();
                if(size == 0) res.push_back(curr->val);
                if(curr->left != NULL) qu.push(curr->left);
                if(curr->right != NULL) qu.push(curr->right);
            }
        }
        return res;
    }
};