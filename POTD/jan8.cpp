
  // Leetcode-> 1458. Max dot product of two subsequences

#include <bits/stdc++.h>
using namespace std;

int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        //creating dp table
        vector<vector<int>>dp(n+1, vector<int>(m+1,INT_MIN));
        //transition state depend upon future states so
        //we will start the loop from n-1 to 0
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                //agar hm array k elements ko le rhe h
                int take= nums1[i]*nums2[j]+ max(0,dp[i+1][j+1]);
                //agar hm 1st array k kisi element skip kr rhe h 
                int skip1=dp[i+1][j];
                //jb hm 2nd array k elemnent ko skip kr rhe h 
                int skip2=dp[i][j+1];
                //state defined as dp[i][j] contains the max sum of subsequence
                //from n-1 and m-1 to 0
                dp[i][j]=max(take,max(skip1,skip2));
            }
        }
        //last grid return krdo
        return dp[0][0];
    }

//Approach-> Dynamic Programming
//TC-> 0(n*m)
//SC-> 0(n*m)