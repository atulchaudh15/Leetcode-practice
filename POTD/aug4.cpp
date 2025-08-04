#include <bits/stdc++.h>
using namespace std;
int totalFruit(vector<int>& fruits) {
        int n= fruits.size();
        int i=0,j=0,max_ans=-1e9;
        unordered_map<int,int>mp;
        while(j<n){
           mp[fruits[j]]++;
           if(mp.size()<=2){
            //agr map m do ya do s km uniue type k fruits h to ans update krdo
            max_ans= max(max_ans, (j-i+1));
           } else{
            //if there are more than two unique fruits in map
            //then shrink the window
            mp[fruits[i]]--;
            //shrink kse kroge pehle freq -- kroge agr freq 0 ho gyi to usko delete krdo 
            //map s
            if(mp[fruits[i]]==0){
                mp.erase(fruits[i]);
            }
            i++;
           }
           j++;
        }
        return max_ans;
    }

//Approach-> Sliding window
//TC->0(n)
//SC->0(n)