
//712. Minimum ASCII Delete Sum for Two Strings

#include <bits/stdc++.h>
using namespace std;

int minimumDeleteSum(string s1, string s2) {
        int n= s1.size();
        int m= s2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        //base case 1: if s2 is empty, then delete all char of s1
        for(int i=1;i<=n;i++){
            dp[i][0]= dp[i-1][0]+int(s1[i-1]);
        }
        //base case 2: if s1 is empty, then delete all char of s2
        for(int j=1;j<=m;j++){
            dp[0][j]= dp[0][j-1]+int(s2[j-1]);
        }
        //filling rest dp table
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //if chars are equal, then no need of deletion
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    //taking minimum of deletion cost of ith char of s1 and jth char of s2
                    dp[i][j]=min(dp[i-1][j]+int(s1[i-1]),
                    dp[i][j-1]+int(s2[j-1]));
                }
            }
        }
        return dp[n][m];
    }

//Approach-> dynamic programming
//TC->0(n*m)
//SC->0(n+m)