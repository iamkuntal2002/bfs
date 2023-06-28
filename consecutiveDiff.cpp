#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/numbers-with-same-consecutive-differences/
class Solution {
public:
    void helper(vector<int> &res, int n,int k,int dig){
        if(n == 0) res.push_back(dig);
        else{
            int el = dig%10;
            if(el+k <10) helper(res,n-1,k,dig*10+el+k);
            if(k && el >= k) helper(res,n-1,k,dig*10+el-k);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        for(int dig = 1;dig<=9;dig++)
            helper(res,n-1,k,dig);
        return res;
    }
};