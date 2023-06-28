#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-height-trees/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<int> adj[n+1];
        vector<int> inorder(n+1);
        queue<int> qu;
        vector<int> res;
        for(auto &ed : edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
            inorder[ed[0]]++;
            inorder[ed[1]]++;
        }
        for(int i =0;i<n;i++){
            if(inorder[i] ==1) qu.push(i);
        }
        while(n>2){
            int size = qu.size();
            n -= size;
            for(int i =0;i<size;i++){
                int node = qu.front();
                qu.pop();
                for(auto adjnode : adj[node]){
                    inorder[adjnode]--;
                    if(inorder[adjnode] == 1) qu.push(adjnode);
                }
            }
        }
        while(!qu.empty()){
            res.push_back(qu.front());
            qu.pop();
        }
        return res;
    }
};