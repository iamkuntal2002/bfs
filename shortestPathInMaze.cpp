#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/shortest-path-in-binary-matrix
class Solution {
public:
    bool isvalid(int x,int y,int n){
        if(x<0 || y<0 || x>=n || y>=n) return false;
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        int dx[] = {1,-1,0,0,1,-1,1,-1};
        int dy[] = {0,0,1,-1,1,1,-1,-1};
        vector<vector<bool>> vis(n+1,vector<bool>(n+1,false));
        queue<vector<int>> qu;
        qu.push({0,0,1});
        vis[0][0] = true;
        while(!qu.empty()){
            auto v = qu.front();
            qu.pop();
            if(v[0] == n-1 && v[1] == n-1) return v[2];
            for(int i =0;i<8;i++){
                int nx = v[0]+dx[i];
                int ny = v[1]+dy[i];
                if(isvalid(nx,ny,n) && !vis[nx][ny] && grid[nx][ny] == 0){
                    vis[nx][ny] = true;
                    qu.push({nx,ny,v[2]+1});
                }
            }
        }
        return -1;
    }
};