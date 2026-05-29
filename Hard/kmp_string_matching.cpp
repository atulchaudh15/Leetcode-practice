

  //KMP- Knuth- Morris- Puth String Mtching Algorithm (GFG)

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> LPS(string &pat, string &txt){
        int n= pat.length();
        int m= txt.length();
        vector<int>lps(n);
        lps[0]=0;
        int len=0;
        int i=1;
        while(i<n){
            //agar equal h
            if(pat[i]==pat[len]){
                //len bdha do kuki ek aur char mil gya h mtlb suffix aur prefix 
                len++;
                //phir usko store krdo lps k usi ith index p 
                lps[i]=len;
                //aur ith ko aage badha do
                i++;
            }else{
                //agar equal nhi h to hm lps of uske pehle waale index p jaege
                if(len != 0){
                    //aur len ko usi k equal krke phirse check krenge
                    len= lps[len-1];
                }else{
                    //agar len 0 ho gyi to mtlb koi suffix ya prefix nhi mila iss index tk
                    lps[i]=0;
                    //i ko aage badha do
                    i++;
                }
            }
        }
        return lps;
        
    }
    vector<int> search(string &pat, string &txt) {
        int n= pat.length();
        int m= txt.length();
        vector<int>res;
        vector<int>lps= LPS(pat,txt);
        //now apply kmp
        int i=0,j=0;
        //kb tk chlega jb tk txt khtm nhi ho jata
        while(i<m){
            //agar dono equal h to i aur j aage badha do
            if(txt[i]==pat[j]){
                i++;
                j++;
                //aur check krlo kahi pat exhaust ya khtm to nhi ho gya agar ho gya
                //to mtlb hme vo txt m mil gya
                if(j==n){
                //agar ho gya to hm log vo index resm push kr denge jhn s pat match hua h txt s
                res.push_back(i-j);
                //aur ho gya h aage bhi mil jaaye pat kahi p txt m
                //kuki abhi txt khtm to hua nhi h to j ko lps[j-1] p le jao 
                //yhi h main fayda kmp m lps ka ab hmko starting s nhi check krna pd rha h
                //ab hm log j s pehle waale char s check krenge
                j= lps[j-1];
              }
            } else{
                //agar match nhi hua to 
                if(j != 0){
                    //to j ko hm log phirse whi bhej denge lps m
                    j= lps[j-1];
                }else{
                    //aur agar j 0 ho gya to mtlb hm log pat ko starting s check krenge
                    //to simple i ko aage bdha do
                    i++;
                }
            }
        }
        return res;
        
        
    }
};

//Approach-> pehle hm log lps bnayenge taaki hm log ko same char na milne p baar baar pattern ko starting s na check krna pde
//phir hm log kmp apply kr denge using lps

//TC-> o(n+m);
//SC-> o(n) + o(n); 
