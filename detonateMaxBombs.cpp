#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/detonate-the-maximum-bombs
class Solution {
public:
    void dfs(vector<vector<int>> &g, int node,int &count,vector<bool> &vis){
        vis[node] = true;
        count++;
        for(auto adjnode : g[node]){
            if(!vis[adjnode]) dfs(g,adjnode,count,vis);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n+1);
        for(int i =0;i<n;i++){
            long long int x1 = bombs[i][0];
            long long int y1 = bombs[i][1];
            long long int r1 = bombs[i][2];
            for(int j =0;j<n;j++){
                if(i!=j){
                    int x2 = bombs[j][0];
                    int y2 = bombs[j][1];
                    int r2 = bombs[j][2];
                    long long int X = (x2-x1)*(x2-x1);
                    long long int Y = (y2-y1)*(y2-y1);
                    long long int R = r1*r1;
                    if(X+Y <= R){
                        graph[i].push_back(j);
                    }
                }
            }
        }
        int ans = 0;
        vector<bool> vis(n+1,false);
        for(int i = 0;i<n;i++){
            int count =0;
            dfs(graph,i,count,vis);
            ans = max(ans,count);
            vis.clear();
            vis = vector<bool>(n+1,false);
        }
        return ans;
    }
};