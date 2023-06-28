#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/jump-game-iii
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start<0 || start>=arr.size() || arr[start]<0) return false;
        if(arr[start] == 0) return true;
        arr[start] = -arr[start];
        return canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
    }
};


class Solution2 {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> qu;
        qu.push(start);
        while(!qu.empty()){
            int i = qu.front();
            qu.pop();
            if(i+arr[i]< arr.size()){
                if(arr[i+arr[i]] == 0) return true;
                else if(arr[i+arr[i]] > 0) qu.push(i+arr[i]); 
            }
            if(i-arr[i] >= 0){
                if(arr[i-arr[i]] == 0) return true;
                else if(arr[i-arr[i]] >0) qu.push(i-arr[i]);
            }
            arr[i] = -1;
        }
        return false;
    }
};