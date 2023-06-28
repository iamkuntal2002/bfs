#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/is-graph-bipartite
class Solution {
public:
    bool bfs(vector<vector<int>> &g, vector<int> &color,int src){
        queue<int> qu;
	    color[src] = 1;
	    qu.push(src);
	    while(!qu.empty()){
	        int node = qu.front();
	        qu.pop();
	        for(int v : g[node]){
	            if(color[v] == -1){
	                color[v] = color[node] == 1 ? 0 : 1;
	                qu.push(v);
	            }
	            else if(color[v] == color[node]) return false;
	        }
	    }
	    return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        // vector<int> adj[n];
        vector<int> color(n,-1);
        for(int i =0;i<n;i++){
            if(color[i] == -1)
                if(bfs(graph,color,i) == false) return false;
        }
        return true;
    }
};