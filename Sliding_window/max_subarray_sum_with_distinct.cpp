#include<bits/stdc++.h>
using namespace std;
long long maximumSubarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        //kuki isme distinct element poocha h to track krna pdega hr elemtn ka frequency
        unordered_map<int,int>mp;
        long long maxSum= 0;
        long long sum=0;
        //dono pointers ko start p rakh diya
        int i=0,j=0;
        //ab hm log window khn tak slide kregi vo likhenge
        while(j<n){
            //ab hm log sum calculate krte rhenge starting k elements ka jb tk 
            //hm log window size k paas ni pahoch jaate
            sum= sum+nums[j];
            //sum calculate kro aur frequency bhi calculate krlo
            mp[nums[j]]++;
            //ab hm log window size fix kr rhe h j pointer ko move krenge jb tk window
            //size hit ni ho jaati
            //window size (j-1+1)
            if(j-i+1 <k) j++;
            //ab agar window size hit ho gyi tb hm log sum ko save kr lenge
            // max track krne  k liye
            else if(j-i+1 ==k){
                //har window ka sum calculate kr lenge
                //aur hm sum tbhi calculate krnege jb mp ka size k k equal ho mtlb saare
                //element distinct ho
                if(mp.size()==k){
                    maxSum= max(maxSum,sum);
                }
                //ab hm log first element mtlb i ko sum s remove kr denge kuki aage badhana
                sum= sum-nums[i];
                //sum calvulate krne k baar uski frequency hta do map s
                mp[nums[i]]--;

                //aur hn sbse imp agar ek element ka kaam ho gya to usko hta do map s kuki
                //map zero frequency waale ko bhi store rkhta h
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                //dono pointer move krdo (mtlb window slide krdo)
                i++; j++;
            }

        }
        return maxSum;

    }
