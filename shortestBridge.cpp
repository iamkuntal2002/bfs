#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/shortest-bridge/
class Solution {
public:
    bool isvalid(vector<vector<int>>& grid, int i,int j,int n){
        if(i<0 || j<0 || i>= n || j>= n || grid[i][j] != 1) return false;
        return true;
    }
    void floodFill(vector<vector<int>>& grid, int i,int j, int n, vector<pair<int,int>> &st){
        grid[i][j] = 0;
        st.push_back({i,j});
        if(isvalid(grid,i,j+1,n)) floodFill(grid,i,j+1,n,st);
        if(isvalid(grid,i,j-1,n)) floodFill(grid,i,j-1,n,st);
        if(isvalid(grid,i+1,j,n)) floodFill(grid,i+1,j,n,st);
        if(isvalid(grid,i-1,j,n)) floodFill(grid,i-1,j,n,st);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int,int>> x;
        vector<pair<int,int>> y;
        int count =0;
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] == 1){
                    count++;
                    if(count ==1) floodFill(grid,i,j,n,x);
                    if(count ==2) floodFill(grid,i,j,n,y);
                }
            }
        }
        
        int ans = INT_MAX;
        for(auto prx : x){
            for(auto pry : y){
                int dist = abs(prx.first - pry.first) + abs(prx.second - pry.second)-1;
                ans = min(ans,dist);
            } 
        }
        return ans;
    }
};