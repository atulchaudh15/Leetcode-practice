#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int transaction, vector<int>& prices,vector<vector<int>>& dp, int n){
        if(idx==n || transaction==4) return 0;
        
        //memo check
        if(dp[idx][transaction] != -1) return dp[idx][transaction];
        //in this ques we use logic as
        //0-buy
        //1-sell
        //2-buy
        //3-sell
        //As we can notice a pattern as at even term it is buy and at odd term it is sell
        if(transaction % 2 == 0){
            //At even term we either buy or not buy (if we buy transaction cnt is increased by 1)
            dp[idx][transaction]= max(-prices[idx] + solve(idx+1,transaction+1,prices,dp,n), 0 + solve(idx+1, transaction,prices,dp,n));
        } else {
            ////At odd term we either sell or not sell (if we sell transaction cnt is increased by 1)
            dp[idx][transaction]= max(prices[idx] + solve(idx+1, transaction+1,prices,dp,n), 0 + solve(idx+1, transaction,prices,dp,n));
        }
        return dp[idx][transaction];
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        //we start from the first index
        //transaction cnt also start with 1->4
        return solve(0,0,prices,dp,n);
    }