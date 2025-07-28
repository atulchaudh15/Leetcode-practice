#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp){
        //memoization wala code h ye
        int n= coins.size();
        //ye base case h
        if(idx==0){
            if(amount % coins[0] ==0) return amount/coins[0];
            else return 1e9;
        }
        
        if(dp[idx][amount] != -1) return dp[idx][amount];
        
        int notTake= 0 + solve(idx-1, amount, coins, dp);
        int Take= 1e9;
        if(coins[idx] <= amount)
          Take= 1 + solve(idx,amount- coins[idx], coins, dp);

        return dp[idx][amount]= min(notTake, Take);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans= solve(n-1,amount,coins,dp);
        //agr kbhi -1 return krna ho kisi ques m for invalid case to uske 
        //last m ans return krne s pehle check lga lena
        //yhi wala
        return(ans>= 1e9)?-1 : ans;
    }
