#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> qu;
        if(root == NULL) return res;
        qu.push(root);
        bool even = false;
        while(!qu.empty()){
            int size = qu.size();
            vector<int> temp;

            for(int i =0;i<size;i++){
                TreeNode *node = qu.front();
                qu.pop();
                temp.push_back(node->val);
                if(node->left != NULL){
                    qu.push(node->left);
                }
                if(node->right != NULL){
                    qu.push(node->right);
                }
            }
            if(even == true){
                reverse(temp.begin(),temp.end());
            }
            even = !even;
            res.push_back(temp);
        }
        return res;
    }
};