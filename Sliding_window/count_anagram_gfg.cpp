#include<bits/stdc++.h>
using namespace std;
int search(string &pat, string &txt) {
        //code here
        int ans=0;
        int n= txt.size();
        int k= pat.size();
        unordered_map<int,int>mp;
        for(auto &p : pat){
            mp[p]++;
        }
        int size= mp.size();
        int i=0,j=0;
        while(j<n){
            //check kro pehle ki ky str[j], map m present h 
            //agar h to uska cnt -- krdo
            if(mp.find(txt[j]) != mp.end()){
                mp[txt[j]]--;
                //aur agar cnt =0 ho gya to map ka size bhi -- krod (v imp.)
                if(mp[txt[j]]==0) size--;
            }
            //agar size hit ni hua to j ko ++ krte rho
            if(j-i+1 < k) j++;
            //agar size hit ho gya
            else if(j-i+1 == k){
                //to do condition hongi ya to map ka size 0 ho ya ni hoga 
                //agar size 0 h to hme anagram mil gya h
                if(size==0){
                    ans++;
                }
                    //agar size 0 nhi h to vo hmara ans nhi h to slide krdo
                    //lekin slide krne s pehle hmko i wala apne map s htana pdega
                    //agar ith element hmare map m presnet h to usko htana(yhn p mtlb
                    //char add krod kuki jb mil rha tha tb hm log -- kr rhe the to jb 
                    //aur htana->(uska freq ++ krdo aur agar freq zero ho jaaye)
                    if(mp.find(txt[i]) != mp.end()){
                        mp[txt[i]]++;
                        //aur agar freq 0 s jyada ho gyi to size bhi plus krod
                        if(mp[txt[i]] ==1) size++;
                    }
            //ab slide krdo
            i++;
            j++;
        }
     }
     return ans;
}

//SC->o(n)
//TC->o(n-k+1) , total windows