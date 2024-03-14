#include<bits/stdc++.h>
long solve(int idx, long *values, int n, bool flag, vector<vector<long>>&dp){
    if(idx==n) return 0;
    // only pick if you can buy
    if(dp[idx][flag]!=-1) return dp[idx][flag];

    long profit = 0;
    if(flag){
        //can buy or cannot buy
        profit = max(-values[idx] + solve(idx+1, values, n, false, dp), solve(idx+1, values, n, true, dp));
    }
    else{
        //can sell it or can sell later
        profit = max(values[idx] + solve(idx+1, values, n, true, dp), solve(idx+1, values, n, false, dp));
    }
    return dp[idx][flag]=profit;
}

long getMaximumProfit(long *values, int n)
{
    //can perform multiple buy and sell 
    vector<vector<long>>dp(n, vector<long>(2, -1));
    return solve(0, values, n, true, dp);
}