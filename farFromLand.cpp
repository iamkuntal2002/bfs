#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/as-far-from-land-as-possible/
class Solution {
public:
    bool isvalid(int i,int j,int n,int m){
        if(i<0 || j<0 || i>= n || j>= m) return false;
        return true;
    }
    int maxDistance(vector<vector<int>>& grid) {
       queue<pair<int,int>> qu;
       int ans = -1;
       int n = grid.size();
       int m = grid[0].size();
       for(int i =0;i<n;i++){
           for(int j =0;j<m;j++){
               if(grid[i][j] == 1) qu.push({i,j});
            }
        }   
        if(qu.size() == n*m) return ans;
        // ans = 0;
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,-1,1};
        while(!qu.empty()){
            int size  = qu.size();            
            ans++;
            // qu.pop();
            for(int p = 0;p<size;p++){
                int r = qu.front().first;
                int c = qu.front().second;
                qu.pop();
                for(int i =0;i<4;i++){
                    int nx = r + dx[i];
                    int ny = c + dy[i];
                    if(isvalid(nx,ny,n,m) && grid[nx][ny] == 0){
                        qu.push({nx,ny});
                        grid[nx][ny] = 1;
                    }
                }
            }
        }
        return ans;
    }
};