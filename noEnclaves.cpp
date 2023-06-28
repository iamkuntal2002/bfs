#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/number-of-enclaves
class Solution {
public:
    int count;
    bool isvalid(int i, int j, int m,int n, vector<vector<int>>& grid){
        if(i>=0 && j>=0 && i<m && j<n && grid[i][j]) return true;
        return false;
    }
    void dfs(int i,int j, int m,int n, vector<vector<int>>& grid){
        count++;
        grid[i][j] = 0;
        if(isvalid(i,j+1,m,n,grid)) dfs(i,j+1,m,n,grid);
        if(isvalid(i,j-1,m,n,grid)) dfs(i,j-1,m,n,grid);
        if(isvalid(i+1,j,m,n,grid)) dfs(i+1,j,m,n,grid);
        if(isvalid(i-1,j,m,n,grid)) dfs(i-1,j,m,n,grid);        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                int temp =0;
                if(i*j == 0 || i == m-1 || j== n-1)
                    if(grid[i][j] == 1) dfs(i,j,m,n,grid);                
            }
        }
        count =0;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                // int curr =0;
                if(grid[i][j] == 1) count++;
            }
        }
        return count;
    }
};