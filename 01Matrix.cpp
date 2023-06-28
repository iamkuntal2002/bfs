#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/01-matrix/
class Solution {
public:
    bool isvalid(int i,int j, int m, int n){
        if(i <0 || j< 0 || i>= m || j>= n ) return false;
        return true;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m,vector<int>(n,-1));
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>> qu;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(mat[i][j] == 0){
                    res[i][j] = 0;
                    qu.push({i,j});
                }
            }
        }
        while(!qu.empty()){
            auto pr = qu.front();
            qu.pop();
            for(int i= 0;i<4;i++){
                int nx = pr.first + dirs[i][0];
                int ny = pr.second + dirs[i][1];
                if(isvalid(nx,ny,m,n) && res[nx][ny] == -1){
                    qu.push({nx,ny});
                    res[nx][ny] = res[pr.first][pr.second]+1;
                }
            }
        }
        return res;
    }
};
class Solution2 {
public:
    bool isvalid(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m) return false;
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> res(n,vector<int>(m,0));
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,pair<int,int>>> qu;
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                if(mat[i][j] == 0){
                    qu.push({0,{i,j}});
                    vis[i][j] = true;
                }
            }
        }
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        while(!qu.empty()){
            auto pr = qu.front();
            qu.pop();
            int dist = pr.first;
            int x = pr.second.first;
            int y = pr.second.second;
            // res[x][y] = dist;
            for(int i =0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(isvalid(nx,ny,n,m) && !vis[nx][ny] && res[nx][ny] == 0){
                    vis[nx][ny] = true;
                    qu.push({dist+1,{nx,ny}});
                    // res[nx][ny] = res[x][y] +1;
                    res[nx][ny] = dist+1;
                }
            }
        }
        return res;
    }
};