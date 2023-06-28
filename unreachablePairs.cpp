#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
class Solution {
public:
    void dfs(vector<int> adj[],int node, vector<bool> &vis,int &comp){
        vis[node] = true;
        comp++;
        for(auto adjnode : adj[node]){
            if(!vis[adjnode]) dfs(adj,adjnode,vis,comp);
            }
        }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n+1];
        for(auto &ed : edges){
            int u = ed[0];
            int v = ed[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long ans = 0;
        int comp = 0;
        vector<int> temp;
        vector<bool> vis(n+1,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                comp =0;
                dfs(adj,i,vis,comp);
                temp.push_back(comp);
                }
            }
        int total = 0;
        for(int i = 0; i<temp.size();i++){
            ans += (long)temp[i]*(n-total-temp[i]);
            total+= temp[i];
            }
        return ans;
    }
};