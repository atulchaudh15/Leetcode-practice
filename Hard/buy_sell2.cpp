#include<bits/stdc++.h>
using namespace std;
//memoization
int solve(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp){
        int n= prices.size();
        int profit=0;
        //Base case
        //if we reach at last index, to ye ho skta h ki shyd hmne koi stock buy kiya ho
        //to it is impossible to sell the stock afterwards
        //if we do not sell that stock then we will face the loss of prices equal to
        //that stock, So it is better to return 0 rather than returning
        //some negative value 
        if(idx==n) return 0;
        //so if we are standing at ith index and buy is 1 then only we can buy otherwise
        //to sell we need buy to be 0(which means we have not bought any stock till now)

        if(dp[idx][buy] != -1) return dp[idx][buy];

        if(buy){
            //if buy=1, we have two choices we can either buy that stock or not
            profit= max(-prices[idx]+ solve(idx+1,0,prices,dp), 0 + solve(idx+1,1,prices,dp));
        } else {
            //if buy=0, again we have two choices either we can sell that stock or not
            profit= max(prices[idx]+ solve(idx+1,1,prices,dp), 0+ solve(idx+1,0,prices,dp));
        }
        return dp[idx][buy]= profit;
}
int maxProfit(vector<int>& prices){
        int n= prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        return solve(0,1,prices,dp);
}