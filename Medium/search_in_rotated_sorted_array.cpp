
  //LEETCODE->81. Search in Rotated Sorted Array II


#include <bits/stdc++.h>
using namespace std;
bool search(vector<int>& nums, int target) {
        int low=0;
       int high=nums.size()-1;
       while(low<=high){
            int mid=low+(high-low)/2;
            //change this into bool instead of returning the index
            if(nums[mid]==target) return true;

            //just need to add one more edge case
            //suppose the first,mid and last element of the array are equal
            //in this case we need a check to trim down the search space
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }

            //check if left half is sorted
            if(nums[low]<=nums[mid]){
                //check if the target is lying in this range
            if(nums[low]<=target && target<=nums[mid]){
                    high=mid-1; //this eliminates right half
            }else{
                    low= mid+1;//this eliminates left half
            }
            
            } else {
                //if the right half is sorted
                if(nums[mid]<=target && target<=nums[high]){
                    low=mid+1;//this eliminates left half
                }else{
                    high=mid-1;//this eliminates right half
                }
            }       
        } 
        return false;
    }
//Approach -> binary search
//KEY POINT-> we need to trim down the search space in case of equal values of low,mid and high
//TC->0(long n)
//SC->0(1)