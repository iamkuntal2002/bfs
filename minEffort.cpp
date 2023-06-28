#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/path-with-minimum-effort/
class Solution {
public:
    bool isvalid(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m) return false;
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = 0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> qu;    //dist,i,j
        qu.push({0,{0,0}});
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        while(!qu.empty()){
            auto pr = qu.top();
            qu.pop();
            int dst = pr.first;
            int x = pr.second.first;
            int y = pr.second.second;
            if(x == n-1 && y == m-1) return dst;
            for(int i =0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(isvalid(nx,ny,n,m)){
                    int ndst = max(dst,abs(heights[x][y]- heights[nx][ny]));
                    if(ndst < dist[nx][ny]){
                        dist[nx][ny] = ndst;
                        qu.push({ndst,{nx,ny}});
                    }
                }
            }
        }
        return 0;
    }
};