        
           //LEETCODE- 1140. Stone Game II

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int dp[2][101][101];
    int solve(int person, int idx, int m, vector<int>& piles){
        //base case
        if(idx >= n) return 0;
        int stone=0;
        if(dp[person][idx][m] != -1) return dp[person][idx][m];
        int res= (person==1) ? INT_MIN : INT_MAX;

        for(int x=1;x<=min(2*m, n-idx);x++){
           stone += piles[idx+x-1];
           
           if(person==1){ //alice ki chance h
                res= max(res, stone + solve(0,idx+x,max(m,x),piles));
           }else{ //bob
                res= min(res, solve(1,idx+x, max(m,x),piles));
           }
        }
        return dp[person][idx][m]= res;
    }
    int stoneGameII(vector<int>& piles) {
        n= piles.size();
        memset(dp,-1, sizeof(dp));
        return solve(1,0,1,piles);
    }
};

//TC-> o(n);
//SC-> o(2*n*n);
//Approach-> DP