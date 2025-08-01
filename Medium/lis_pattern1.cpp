#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int prev_idx, int n, vector<int>& nums, vector<vector<int>>& dp){
        //base case
        //full array is exhausted
        if(idx==n) return 0;

        if(dp[idx][prev_idx+1] != -1) return dp[idx][prev_idx+1];
        //choice diagram
        //not take (no increase in length)
        int not_take= 0 + solve(idx+1, prev_idx, n, nums, dp);
        //take (increase length by 1)
        //but in this we need to check two condn:
        //first-> we will definately take first element
        //second->we will take that element if and only if it is grater than previous element 
        int take= -1e9;
        if(prev_idx == -1 || nums[idx] > nums[prev_idx]){
            take= max(take, 1 + solve(idx+1, idx, n, nums, dp));
        }
        //take max of both take or not take
        return dp[idx][prev_idx+1]= max(take, not_take);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return solve(0,-1,n,nums,dp);
    }