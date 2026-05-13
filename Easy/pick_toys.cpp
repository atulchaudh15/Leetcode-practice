

   //GFG-> Maximize Toys

#include<bits/stdc++.h>
using namespace std;

int toyCount(int N, int K, vector<int> arr) {
        // code here
        int cnt=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            //agar koi toy mehnga h to turant cnt return krdo
            if(arr[i]>K) break;
            else{
                K= K-arr[i];
                cnt++;
            }
        }
        return cnt;
    }

//Approach-> sorting + greedy

//TC-> O(n. logn)
//SC-> o(1)