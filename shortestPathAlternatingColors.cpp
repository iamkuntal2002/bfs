#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/shortest-path-with-alternating-colors/
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> res(n, -1);
        vector<bool> vis1(n, false), vis2(n, false);
        vector<vector<pair<int, int>>> vp(n);
        queue<pair<int, int>> q;

        for(auto &it : redEdges) vp[it[0]].push_back({it[1], 1});
        for(auto &it : blueEdges) vp[it[0]].push_back({it[1], 2});

        res[0] = 0;
        vis1[0] = true;
        vis2[0] = true;
        int temp = 1;

        for(auto &it : vp[0])
        {
            q.push(it);
            //the first nodes connected to 0 always have the required distance is 1
            if(res[it.first] == -1) res[it.first] = temp;
        }

        while(!q.empty())
        {
            int len = q.size();
            temp++;
            for(int i=0; i<len; ++i)
            {
                auto val = q.front();
                q.pop();
                if(val.second == 1) vis1[val.first] = true;
                else vis2[val.first] = true;

                for(auto &it : vp[val.first])
                {
                    //if prev color and (current color  is same of vis) then continue 
                    if(val.second == 1 && (vis2[it.first] || it.second==1)) continue;
                    if(val.second == 2 && (vis1[it.first] || it.second==2)) continue;
                    //push the next node
                    q.push(it);                      
                    if(res[it.first] == -1) res[it.first] = temp;
                }
            }
        }
        return res;
    }
};