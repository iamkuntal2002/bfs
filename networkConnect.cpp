#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/
class Solution {
public:
    void dfs(vector<int> adj[],int node, vector<bool> &vis){
        vis[node]= true;
        for(auto adjnode : adj[node]){
            if(!vis[adjnode]) dfs(adj,adjnode,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> adj[n+1];
        int edges = connections.size();
        if(edges < n-1) return -1;
        for(auto &v : connections){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<bool> vis(n+1,false);
        int component= 0;
        for(int i =0; i< n;i++){
            if(!vis[i]){
                component++;
                dfs(adj,i,vis);
            }
        }
        return component -1;
    }
};