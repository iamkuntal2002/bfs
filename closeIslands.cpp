#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/number-of-closed-islands
class Solution {
public:
    bool isvalid(int i,int j, int m,int n, vector<vector<int>> &grid){
        if(i>= 0 && j>=0 && i<m && j<n && grid[i][j] == 0) return true;
        return false;
    }
    void dfs(int i,int j, int m, int n, vector<vector<int>> &grid){
        grid[i][j] = 1;
        if(isvalid(i,j+1,m,n,grid)) dfs(i,j+1,m,n,grid);
        if(isvalid(i,j-1,m,n,grid)) dfs(i,j-1,m,n,grid);
        if(isvalid(i+1,j,m,n,grid)) dfs(i+1,j,m,n,grid);
        if(isvalid(i-1,j,m,n,grid)) dfs(i-1,j,m,n,grid);        
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i =0; i<m;i++){
            for(int j =0; j<n;j++){
                if(i*j ==0 || i == m-1 || j == n-1){
                    if(grid[i][j] == 0) dfs(i,j,m,n,grid);
                }
            }
        }
        int ans =0;
        for(int i =0; i<m;i++){
            for(int j =0; j<n;j++){
                if(grid[i][j] == 0){
                    ans++;
                    dfs(i,j,m,n,grid);
                }
            }
        }
        return ans;
    }
};