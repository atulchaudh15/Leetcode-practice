#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int buy, vector<int>& prices, vector<vector<int>>&dp, int n){
        //Base case
        if(idx>=n) return 0;
        //if buy is 1 it means we can buy the stock

        if(dp[idx][buy] != -1) return dp[idx][buy];

        if(buy){
            //buy or not buy
            dp[idx][buy]= max(-prices[idx] + solve(idx+1,0,prices,dp,n), 0 + solve(idx+1,1,prices,dp,n));
        } else {
            //sirf ek change hota h agr hm sell kr d=rhe h to next to the next day p shift honge ie idx+2 bs
            dp[idx][buy]= max(prices[idx] + solve(idx+2,1,prices,dp,n), 0 + solve(idx+1,0,prices,dp,n));
        }
        return dp[idx][buy];

    }