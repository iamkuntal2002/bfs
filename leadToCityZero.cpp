#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> adj[n+1];
        vector<bool> vis(n+1,false);
        queue<int> qu;
        qu.push(0);
        //vis[0] = true;
        set<pair<int,int>> st;
        for(auto &con : connections){
            int u=con[0];
            int v= con[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            st.insert({u,v});
        }
        int count = 0;
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            if(!vis[node]){
                vis[node]= true;
                for(auto adjnode : adj[node]){
                    qu.push(adjnode);
                    if(!vis[adjnode] && st.find({adjnode,node}) == st.end()){
                        //qu.push(adjnode);
                        count++;
                    }
                }
            }
        }
        return count;
                        
    }
};