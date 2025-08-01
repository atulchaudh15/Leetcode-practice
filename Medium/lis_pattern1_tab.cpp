
//Tabulation with space optimised version

#include <bits/stdc++.h>
using namespace std;
int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int>next(n+1, 0);
        vector<int>curr(n+1,0);
        for(int idx=n-1;idx>=0;idx--){
            for(int prev_idx= idx; prev_idx>=-1;prev_idx--){
                int not_take= 0 + next[prev_idx+1];
                //take (increase length by 1)
                //but in this we need to check two condn:
                //first-> we will definately take first element
                //second->we will take that element if and only if it is grater than previous element 
                int take= -1e9;
                if(prev_idx == -1 || nums[idx] > nums[prev_idx]){
                    take= max(take, 1 + next[idx+1]);
                }
                curr[prev_idx+1]= max(take, not_take);
            }
            next= curr;
        }
        return next[0];
    }

//complexity
//TC -> O(n^2)
//SC -> 0(n) *2
