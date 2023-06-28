#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/number-of-provinces
class Solution {
public:
    void dfs(int node,vector<vector<int>>& isConnected,vector<bool> &vis){
        for(int i = 0;i<isConnected.size();i++){
            if(isConnected[node][i] == 1 && !vis[i]){
                vis[i] = true;
                dfs(i,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        vector<bool> vis(n+1,false);
        for(int i =0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,isConnected,vis);
            }
        }
        return count;
    }
};