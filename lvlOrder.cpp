#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        queue<TreeNode *> store;
        store.push(root);
        while(!store.empty()){
            int size = store.size();
            vector<int> temp;
            for(int i =0; i<size; i++){
                TreeNode * node = store.front();
                store.pop();                          
                if(node->left != NULL) store.push(node->left);
                if(node->right != NULL) store.push(node->right);
                temp.push_back(node->val);
            }
            result.push_back(temp);
        }
        return result;
    }
};