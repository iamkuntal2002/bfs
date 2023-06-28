#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/max-area-of-island
class Solution {
public:
    bool isvalid(int i,int j, int m, int n, vector<vector<int>> &grid){
        if(i>=0 && j>= 0 && i<m && j<n && grid[i][j] == 1) return true;
        return false;
    }
    void dfs(int i,int j, int m,int n, vector<vector<int>> &grid, int &area){
        area++;
        grid[i][j] = 0;
        if(isvalid(i,j+1,m,n,grid)) dfs(i,j+1,m,n,grid,area);
        if(isvalid(i,j-1,m,n,grid)) dfs(i,j-1,m,n,grid,area);
        if(isvalid(i+1,j,m,n,grid)) dfs(i+1,j,m,n,grid,area);
        if(isvalid(i-1,j,m,n,grid)) dfs(i-1,j,m,n,grid,area);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans =0;
        for(int i =0;i<m;i++){
            for(int j =0; j<n;j++){
                int maxarea = 0;
                if(grid[i][j] == 1){
                    dfs(i,j,m,n,grid,maxarea);
                    ans = max(ans,maxarea);
                }
            }
        }
        return ans;
    }
};