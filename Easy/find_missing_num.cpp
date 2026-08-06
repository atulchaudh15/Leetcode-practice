
     // LEETCODE- 3731. Find Missing Elements

#include<bits/stdc++.h>
using namespace std;
vector<int> findMissingElements(vector<int>& nums) {
        /*
        //Method 1;
        //TC-> o(n log n), sorting
        //SC-> o(n), map
        int n= nums.size();
        unordered_map<int,int>mp;
        int maxi= *max_element(nums.begin(), nums.end());
        int mini= *min_element(nums.begin(), nums.end());
        vector<int>res;
        for(auto &num : nums){
            mp[num]++;
        }
        for(int i=mini;i<=maxi;i++){
            //mtlb map m vo value present nhi h
            if(mp.find(i) ==mp.end()){
                //to hm usko apne result m include kr lenge
                res.push_back(i);
            }
        }
         
        sort(res.begin(), res.end());
        return res;
        */

       //Method 2;
       //TC-> o(n)
       //SC-> o(1)
       int n= nums.size();
       sort(nums.begin(), nums.end());
       vector<int>res;
       int m= nums[0];
       int maxi= nums[n-1];
       int i=0;
       for(m=m;m<=maxi;m++){
            if(nums[i]==m){
                i++;
                continue;
            }else{
                res.push_back(m);
            }
       }

       return res;
        
    }

//Approach-> sorting + simulation

