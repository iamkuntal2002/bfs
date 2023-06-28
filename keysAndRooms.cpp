#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/keys-and-rooms
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n,false);
        queue<int> qu;
        qu.push(0);
        vis[0] = true;
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            for(auto adjnode : rooms[node]){
                if(!vis[adjnode]){
                    vis[adjnode] = true;
                    qu.push(adjnode);
                }
            }
        }
        for(auto reach : vis){
            if(!reach) return false;
        }
        return true;
    }
};