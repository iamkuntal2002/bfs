#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int,int>> qu;
        qu.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        int moves =1;
        while(!qu.empty()){
            int size = qu.size();
            for(int i =0;i<size;i++){
                auto pr = qu.front();
                qu.pop();
                for(int j =0;j<4;j++){
                    int nx = pr.first +dirs[j][0];
                    int ny = pr.second + dirs[j][1];
                    if(nx <0 || ny <0 || nx >= m || ny >= n || maze[nx][ny] == '+') continue;
                    if(nx == 0 || ny == 0 || nx == m-1 || ny == n-1) return moves;
                    maze[nx][ny] = '+';
                    qu.push({nx,ny});
                }
            }
            moves++;
        }
        return -1;
    }
};