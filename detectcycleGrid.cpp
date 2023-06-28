#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/detect-cycles-in-2d-grid
// need to check where the length is >=4 but that is not a circle, in that case we have to use the currdfs 
class Solution {
public:
    bool isvalid(int i,int j,int n,int m,vector<vector<bool>>& vis){
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j]) return false;
        return true;
    }
    bool dfs(vector<vector<char>>& grid,vector<vector<bool>>& vis,int i,int j,int n,int m,int pi,int pj,int len){
        vis[i][j] = true;
        if(isvalid(i,j+1,n,m,vis) && grid[i][j+1] == grid[i][j] && (pi != i || pj != j+1)) return dfs(grid,vis,i,j+1,n,m,i,j,len+1);
        else if(len>3) return true;
        if(isvalid(i,j-1,n,m,vis) && grid[i][j-1] == grid[i][j] && (pi != i || pj != j-1)) return dfs(grid,vis,i,j-1,n,m,i,j,len+1);
        else if(len>3) return true;
        if(isvalid(i+1,j,n,m,vis) && grid[i+1][j] == grid[i][j] && (pi != i+1 || pj != j)) return dfs(grid,vis,i+1,j,n,m,i,j,len+1);
        else if(len>3) return true;
        if(isvalid(i-1,j,n,m,vis) && grid[i-1][j] == grid[i][j] && (pi != i-1 || pj != j)) return dfs(grid,vis,i,j,n,m,i-1,j,len+1);
        else if(len>3) return true;
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!vis[i][j]){
                    if(dfs(grid,vis,i,j,n,m,-1,-1,0)) return true;
                }
            }
        }
        return false;
    }
};
// ["b","a","c"]
// ["c","a","c"]
// ["d","d","c"]
// ["b","c","c"]