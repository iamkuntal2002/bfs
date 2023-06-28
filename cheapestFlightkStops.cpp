#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/cheapest-flights-within-k-stops
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto f : flights) adj[f[0]].push_back({f[1],f[2]});
        queue<pair<int,pair<int,int>>> qu;
        vector<int> dist(n,INT_MAX);
        qu.push({0,{src,0}});   //stops,start,cost
        dist[src] =0;
        while(!qu.empty()){
            auto pr = qu.front();
            qu.pop();
            int stops = pr.first;
            int start = pr.second.first;
            int cost = pr.second.second;
            if(stops > k) continue;
            for(auto it : adj[start]){
                int adjNode = it.first;
                int adjCost = it.second;
                if(dist[adjNode] > adjCost + cost && stops <= k){
                    dist[adjNode] = cost + adjCost;
                    qu.push({stops+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};