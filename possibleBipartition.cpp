#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/possible-bipartition/
class Solution {
public:
bool bfs(vector<int> adj[], vector<int> &color,int src){
      queue<int> qu;
	    color[src] = 1;
	    qu.push(src);
	    while(!qu.empty()){
	        int node = qu.front();
	        qu.pop();
	        for(int v : adj[node]){
	            if(color[v] == -1){
	                color[v] = color[node] == 1 ? 0 : 1;
	                qu.push(v);
	            }
	            else if(color[v] == color[node]) return false;
	        }
	    }
	    return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
				for(auto dis : dislikes){
					adj[dis[0]].push_back(dis[1]);
					adj[dis[1]].push_back(dis[0]);

				}
        vector<int> color(n+1,-1);
        for(int i =0;i<n;i++){
            if(color[i] == -1)
                if(bfs(adj,color,i) == false) return false;
        }
        return true;
    }
};