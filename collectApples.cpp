#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
class Solution {
public:
    int dfs(vector<int> adj[],vector<bool> &vis,vector<bool> &apple,int node,int cost){
        if(vis[node]) return 0;
        vis[node] = true;
        int pathcost = 0;
        for(auto adjnode : adj[node]){
            if(!vis[adjnode]) pathcost += dfs(adj,vis,apple,adjnode,2); //2 is for go and back
        }
        if(pathcost == 0 && !apple[node]) return 0;
        return pathcost + cost;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n+1];
        for(auto ed : edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        vector<bool> vis(n+1,false);
        return dfs(adj,vis,hasApple,0,0);
    }
};