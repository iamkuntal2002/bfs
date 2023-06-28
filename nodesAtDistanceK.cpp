#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    void getParent(TreeNode *root,unordered_map<TreeNode*,TreeNode*> &mp){
        if(root == NULL) return;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            TreeNode *curr = qu.front();
            qu.pop();
            if(curr->left){
                qu.push(curr->left);
                mp[curr->left] = curr;
            }
            if(curr->right){
                qu.push(curr->right);
                mp[curr->right] = curr;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;      //node -> parent
        getParent(root,mp);
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> qu;
        qu.push(target);
        vis[target]= true;
        int curr_dist = 0;
        while(!qu.empty()){
            int size = qu.size();
            if(curr_dist == k) break;
            curr_dist++;
            for(int i =0;i<size;i++){
                TreeNode *node = qu.front();
                qu.pop();
                if(node->left != NULL && !vis[node->left]){
                    qu.push(node->left);
                    vis[node->left] = true;
                }
                if(node->right != NULL && !vis[node->right]){
                    qu.push(node->right);
                    vis[node->right] = true;
                }
                if(mp[node] != NULL && !vis[mp[node]]){
                    qu.push(mp[node]);
                    vis[mp[node]] = true;
                }
            }
        }
        vector<int> res;
        while(!qu.empty()){
            res.push_back(qu.front()->val);
            qu.pop();
        }
        return res;
    }
};