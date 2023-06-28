#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-width-of-binary-tree

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
    // void marked(TreeNode *root){
    //     queue<TreeNode*> qu;
    //     qu.push
    // }
    int widthOfBinaryTree(TreeNode* root) {
        // marked(root);
        if(root == NULL) return 0;
        queue<pair<TreeNode*,unsigned long long int>> qu;
        qu.push({root,0});
        int ans = INT_MIN;
        while(!qu.empty()){
            int size = qu.size();
            unsigned long long int left = qu.front().second;
            unsigned long long int right = 0;
            for(int i =0;i<size;i++){
                auto pr = qu.front();
                qu.pop();
                right = pr.second;
                TreeNode *node = pr.first;
                // if(i == 0) left = val;
                // if(i == size-1) right = val;
                if(node->left) qu.push({node->left,2*right});
                if(node->right) qu.push({node->right,2*right+1});
            }
            ans = max(ans,(int)(right-left+1));
        }
        return ans;
    }
};