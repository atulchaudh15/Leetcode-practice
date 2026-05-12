
    // 1665. Minimum Initial Energy to Finish Tasks


#include <bits/stdc++.h>
using namespace std;
//check ki tc 0(n)
    bool check(vector<vector<int>>& tasks, int mid){
        //ab check krna h iterate krke 
        for(auto &task : tasks){
            int actual= task[0];
            int mini= task[1];

            //edge case ya base case
            //mtlb agar minimum reg energy kisi task ko krne k liye jo chahiye
            //aur hmari paas waali energy usse km h to complete hi ni kr paege
            //to return false
            if(mini > mid){
                return false;
            }
            //wrna energy spend krke task complete krdo
            mid = mid-actual;
        }
        //ab agar yhn tk pahoch gye to mtlb saare task complete kr liye
        //kitni energy m (sirf mid bhar ki energy m hi)
        //to true krdo
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n=tasks.size();
        int l=0;
        int r=1e9;
        auto lambda= [](auto &task1, auto &task2){
            //diff calculate krlo kuki isi ke basis p sort krna h
            int diff1= task1[1]-task1[0];
            int diff2= task2[1]-task2[0];

            //agar diff1 greater hoga to vo pehle aayega wrna baad m 
            return diff1 > diff2;
        };
        //sort ki tc 0(n.log n)
        //sort krdo self defined cond k basis p
        sort(tasks.begin(),tasks.end(),lambda);
        int res= INT_MAX;
        //binary search ki tc 0(log n)
        while(l<=r){
            int mid= l+ (r-l)/2;
            //main check func for BS on ans
            if(check(tasks,mid)){
                res= mid;
                //aur mid ko km krdo
                r= mid-1;
            }else {
                l= mid+1;
            }
        }
        return res;
    }

//APPROACH-> Binary search on answer + sort
//second-> sort + traversal krdo greedily

//TC->o(n.logn)+ o(n)+ o(log n) ~ o(n.log n)
//SC->o(1)