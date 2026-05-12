
   // VARIABLE SIZE WINDOW QUESTION

   //Longest Substring with K Uniques (GFG)

#include<bits/stdc++.h>
using namespace std;
int longestKSubstr(string &s, int k) {
        // code here
        int n= s.length();
        int maxWin=0;
        unordered_map<int,int>mp;
        int i=0,j=0;
        while(j<n){
            mp[s[j]]++;
            int mapSize= mp.size();
            if(j==n-1 && mapSize < k) return -1;
            if(mapSize < k) j++;
            else if(mapSize == k){
                int wind= j-i+1;
                maxWin= max(maxWin, wind);
                j++; 
            } else{
                while(mapSize > k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){ 
                        mp.erase(s[i]);
                        mapSize--;
                    }
                    i++;
                }
                j++;
            }
        }
        return maxWin;
    }

//APPROACH-> isme sbse imp mtlb pehle to ye variable SW tha phir next isme unique k char pooch rha th 
//to do ds dimaag m aaate h map aur set 
//but set hmne isliye ni use kiya kuki isme duplicate elements bhi the aur 
//agar hm window slide krte time ith ko delete krte to set saare ith ko delete kr deta 
//but hme ye ni chahiye the 
//isiliye hmne map use kiya kuki ye freq bhi store krta h 


//TC->o(n.k(size))
//SC->o(n);