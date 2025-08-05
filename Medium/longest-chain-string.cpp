#include <bits/stdc++.h>
using namespace std;

int longestStrChain(vector<string>& words) {
        unordered_map<string,int>mp;
        sort(words.begin(),words.end(),[](string& a, string& b){
            return a.size() < b.size();
        });
        int max_len=0;
        for(auto& word : words){
            int best=0;
            for(int i=0;i<word.size();i++){
                //removing one char
                string pred= word.substr(0,i) + word.substr(i+1);
                //storing the max possible length of of all predecessor after removing ith 
                //char of word 
                best= max(best, mp[pred]);
            }
            //storing thel length of each word which is 1 greater than its predecessor
            mp[word]= best + 1;
            //updating max length of all
            max_len= max(max_len, mp[word]);
        }
        return max_len;
    }

//Approach -> Hashmap + Sorting   

//TC -> 0(n* L) where l is the length of each word in words vector
//SC -> 0(n)