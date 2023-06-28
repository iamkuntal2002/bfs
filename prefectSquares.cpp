#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/perfect-squares/
class Solution {
public:
    int numSquares(int n) {
        int level = 0;
        if(n == 0) return level;
        queue<int> qu;
        qu.push(n);
        while(!qu.empty()){
            int size = qu.size();
            level++;
            for(int i =0;i<size;i++){
                int curr = qu.front();
                qu.pop();
                for(int j =1;j<=n;j++){
                    int rem = curr - j*j;
                    if(rem == 0) return level;
                    else if(rem>0) qu.push(rem);
                }
            }
        }
        return -1;
    }
};