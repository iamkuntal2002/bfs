#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/number-of-islands
class Solution {
public:
bool isvalid(int i, int j, int m, int n, vector<vector<char>> &grid){
    if(i>=0 && j>= 0 && i<m && j < n && grid[i][j] == '1') return true;
    return false;
}
void dfs(vector<vector<char>> &grid,int i, int j, int m,int n,vector<vector<bool>> &vis){
    // grid[i][j] = '0';
    vis[i][j] = true;
    if(isvalid(i,j+1,m,n,grid) && !vis[i][j]) dfs(grid,i,j+1,m,n,vis);
    if(isvalid(i,j-1,m,n,grid) && !vis[i][j]) dfs(grid,i,j-1,m,n,vis);
    if(isvalid(i+1,j,m,n,grid) && !vis[i][j]) dfs(grid,i+1,j,m,n,vis);
    if(isvalid(i-1,j,m,n,grid) && !vis[i][j]) dfs(grid,i-1,j,m,n,vis);
}
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n+1,vector<bool> (m+1,false));
        int ans = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    ans++;
                    dfs(grid,i,j,n,m,vis);
                }
            }
        }
        return ans;
    }
};