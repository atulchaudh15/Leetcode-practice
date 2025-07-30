#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int& k, int transaction, vector<int>& prices, vector<vector<int>>& dp, int n){ 
        if(transaction== (2*k)) return 0;
        if(idx==n) return 0;

        if(dp[idx][transaction] != -1) return dp[idx][transaction];
        
        if(transaction % 2 == 0){
             dp[idx][transaction]= max(-prices[idx] + solve(idx+1,k,transaction+1,prices,dp,n),
            0 + solve(idx+1,k,transaction,prices,dp,n));
        } else {
             dp[idx][transaction]= max(prices[idx] + solve(idx+1,k,transaction+1,prices,dp,n),
            0 + solve(idx+1,k,transaction,prices,dp,n));
        }
        return dp[idx][transaction];

    }
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        //int transaction= 2*k;
        vector<vector<int>>dp(n,vector<int>(2*k,-1));
        return solve(0,k,0,prices,dp,n);
    }