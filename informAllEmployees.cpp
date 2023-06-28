#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/time-needed-to-inform-all-employees
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n+1];
        for(int i =0;i<n;i++){
            if(manager[i] != -1){
                adj[manager[i]].push_back(i);
            }
        }
        int ans = 0;
        queue<int> qu;
        qu.push(headID);
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            // ans += informTime[node];
            for(auto adjnode : adj[node]){
                ans = max(ans,informTime[node]);
                informTime[adjnode] += informTime[node];
                qu.push(adjnode);
            }

        }
        return ans;
    }
};