
  // Leetcode-> 66. Plus One

#include <bits/stdc++.h>
using namespace std;

int repeatedNTimes(vector<int>& nums) {
        int size=nums.size();
        int cnt=size/2;
        map<int,int>mp;
        for(auto &num: nums){
            mp[num]++;
        }
        for(auto& [key,value]: mp){
            if(value==cnt){
                return key;
            }
        }
        return 0;
}

//TC-> 0(n)
//SC-> 0(n)