#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/coin-change
// https://practice.geeksforgeeks.org/problems/coin-change2448/1
class Solution
{
public:
    int helper(vector<int> &coins, vector<vector<int>> &dp, int amount, int ind)
    {
        if (ind >= coins.size() || amount <= 0)
        {
            if (amount == 0)
                return 0;
            else
                return INT_MAX - 1;
        }
        if (dp[ind][amount] != -1)
            return dp[ind][amount];
        int res = -1;
        if (coins[ind] > amount)
        {
            int nottake = 0 + helper(coins, dp, amount, ind + 1);
            res = nottake;
        }
        else
        {
            int take = 1 + helper(coins, dp, amount - coins[ind], ind);
            int nottake = 0 + helper(coins, dp, amount, ind + 1);
            res = min(take, nottake);
        }
        return dp[ind][amount] = res;
    }
    int coinChange(vector<int> &coins, int amount)
    {
        vector<vector<int>> dp(15, vector<int>(100001, -1)); // index,amount
        int res = helper(coins, dp, amount, 0);
        return res == INT_MAX - 1 ? -1 : res;
    }
};

class Solution2
{
public:
    long long helper(int sum, int coins[], int index, vector<vector<long long>> &dp)
    {
        if (index < 0 || sum < 0)
            return 0;
        if (sum == 0)
            return 1;
        if (dp[index][sum] != -1)
            return dp[index][sum];
        long long take = helper(sum - coins[index], coins, index, dp);
        long long nottake = helper(sum, coins, index - 1, dp);
        return dp[index][sum] = take + nottake;
        // return dp[index][sum]=helper(sum-coins[index],coins,index,dp)+helper(sum,coins,index-1,dp);
    }
    long long int count(int coins[], int N, int sum)
    {
        // code here.
        vector<vector<long long>> dp(N + 1, vector<long long>(sum + 1, -1));
        return helper(sum, coins, N - 1, dp);
    }
};

long long f(int i, int val, int *deno, vector<vector<long long>> &dp)
{
    if (i == 0)
    {
        return val % deno[0] == 0;
    }
    if (dp[i][val] != -1)
        return dp[i][val];
    long long notTake = f(i - 1, val, deno, dp);
    long long take = 0;
    if (deno[i] <= val)
    {
        take = f(i, val - deno[i], deno, dp);
    }
    return dp[i][val] = take + notTake;
}
long countWaysToMakeChange(int *deno, int n, int value)
{ // Write your code here    
vector<vector<long long>> dp(n, vector<long long>(value+1, 0));
}