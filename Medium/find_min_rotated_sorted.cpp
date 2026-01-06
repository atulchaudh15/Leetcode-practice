
   //LEETCODE-> 151 min in sorted rotated array

#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
        int mini=INT_MAX;
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            //check if left half is sorted
            if(nums[low]<=nums[mid]){
                //if the left half is sorted then low
                //will be the smallest element
                mini= min(mini,nums[low]);
                //take it and eliminate the left half
                low=mid+1;
            }else{
                //right half is sorted
                //then mid will be the smallest element
                mini= min(mini,nums[mid]);
                //take it and eliminate the right half
                high=mid-1;  
            }
        }
        return mini;
    }
//TC->0(log n)
//SC->0(1)