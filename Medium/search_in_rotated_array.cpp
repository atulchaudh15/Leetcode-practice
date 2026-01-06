
  //LEETCODE->33. Search in Rotated Sorted Array


#include <bits/stdc++.h>
using namespace std;
int search(vector<int>& nums, int target) {
       int low=0;
       int high=nums.size()-1;
       while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
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
        return -1;
    }
//Approach -> binary search
//KEY POINT-> we nee to search for the sorted part in that rotated array
//TC->0(long n)
//SC->0(1)