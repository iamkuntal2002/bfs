#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/course-schedule
class Solution {
public:
    bool dfs(vector<int> adj[],vector<bool> &vis,vector<bool> &dfsvis,int node){
        vis[node] = true;
        dfsvis[node] = true;
        for(auto adjnode : adj[node]){
            if(!vis[adjnode]){
                if(dfs(adj,vis,dfsvis,adjnode)) return true;
            }
            if(vis[adjnode] && dfsvis[adjnode]) return true;
        }
        dfsvis[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }
        vector<bool> vis(numCourses,false);
        vector<bool> dfsvis(numCourses,false);
        for(int i =0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(adj,vis,dfsvis,i)) return false;
            }
        }
        return true;
    }
};
