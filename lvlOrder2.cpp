#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
//without reversing
class Solution {
public:
    int depth(TreeNode* root){
        if(root == NULL)return 0;
		//return the maximum depth of the tree so to find the levels
        return max(depth(root->right),depth(root->left))+1;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
     if(root == NULL)return {};
        int d = depth(root);
		//initialise the empty levels inside a vector
        vector<vector<int> > level(d,vector<int>({})); 
        int i = 0;
		//use a queue to maintain the tree nodes
        queue<TreeNode*> q;
		//push the root node with one element and decrement the level
        q.push(root);
        level[d-1].push_back(root->val);
        q.push(NULL);
        d--;

		// do work while queue is not empty
        while(!q.empty()){
			// extract the node from the queue and remove it from the queue
            TreeNode* temp = q.front();
            q.pop();
            
			//if the node exist check its right and left node
            if(temp){  
				// and if the left and right node exist simply push the value to the vector
                if(temp->left){
                        q.push(temp->left);
                        level[d-1].push_back(temp->left->val);
                    }    
                if(temp->right){
                        q.push(temp->right);
                        level[d-1].push_back(temp->right->val);
                    }
            }                 
            else {
			// to handle condition if NULL found at a node
                if(q.empty()) break;
                d--;
                q.push(NULL);
            }  
        }
		// now without reversing the vector you can simply return the answer
        return level;
    }
};


//reversing
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> qu;
        if(root == NULL) return res;
        qu.push(root);
        while(!qu.empty()){
            int size = qu.size();
            vector<int> temp;
            for(int i =0; i<size; i++){
                TreeNode * node = qu.front();
                qu.pop();
                if(node->left != NULL) qu.push(node->left);
                if(node->right != NULL) qu.push(node->right);
                temp.push_back(node->val);
            }
            res.push_back(temp);            
        }
        reverse(res.begin(), res.end());
        return res;
    }
};