#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/course-schedule-ii
class Solution {
public:
    void getInDeg(vector<int> adj[], vector<int> &in, int v)
    {
        for (int i = 0; i < v; i++)
        {
            for (auto v : adj[i])
            {
                in[v]++;
            }
        }
    }
    vector<int> findOrder(int n, vector<vector<int>>& arr) {
        vector<int> adj[n];
        for (int i = 0; i < arr.size(); i++)
        {
            adj[arr[i][1]].push_back(arr[i][0]);
        }
        vector<int> inDeg(n, 0);
        getInDeg(adj, inDeg, n);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (inDeg[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            topo.push_back(curr);
            for (auto j : adj[curr])
            {
                inDeg[j]--;
                if (inDeg[j] == 0)
                {
                    q.push(j);
                }
            }
        }
        if (topo.size() == n)
        {
            return topo;
        }
        return {};
    }
};