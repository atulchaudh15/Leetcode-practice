
  //2553. Separate the Digits in an Array

#include <bits/stdc++.h>
using namespace std;
vector<int> separateDigits(vector<int>& nums) {
        vector<int>res;
        for(auto &num : nums){
            vector<int>ans;
            while(num>0){
                int digit= num%10;
                ans.push_back(digit);
                num =num/10;
                }
            reverse(ans.begin(),ans.end());
            res.insert(res.end(),ans.begin(),ans.end());
        }
        return res;
    }

//SC->0(2n ~ n)
//TC->0(n*digits)