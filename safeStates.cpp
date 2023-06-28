#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-eventual-safe-states
class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<bool> &vis,vector<bool> &dfsvis,vector<bool> &safe, int node){
        vis[node] = true;
        dfsvis[node] = true;
        for(auto el : graph[node]){
            if(!vis[el]){
                if(dfs(graph,vis,dfsvis,safe,el)) return safe[node] =true;
            }
            else if(vis[el] == true && dfsvis[el] == true){
                return safe[node] = true;
            }
        }
        dfsvis[node] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n,false), dfsvis(n,false), safe(n,false);
        for(int i =0;i<n;i++){
            if(!vis[i]) dfs(graph,vis,dfsvis,safe,i);
        }
        vector<int> ans;
        for(int i =0;i<n;i++){
            if(!safe[i]) ans.push_back(i);
        }
        return ans;
    }
};