

//   LEETCODE : 2213. Longest Substring of One Repeating Character

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    struct Node{
        int maxLen=0;
        int pre=0;
        int suf=0;
        char leftChar=0;
        char rightChar=0;
    };
    vector<Node> seg;
    void buildSeg(int idx, int l, int r, string& s){
        if(l==r){
            seg[idx]= {1,1,1, s[l],s[r]};
            return;
        }
        int mid= l + (r-l)/2;
        buildSeg(2*idx+1, l,mid,s);
        buildSeg(2*idx+2, mid+1,r,s);

        seg[idx]= merge(seg[2*idx+1], seg[2*idx+2], mid-l+1,r-(mid+1)+1);
    }
    Node merge(const Node& L, const Node& R, int leftLen, int rightLen){
        Node res;
        
        res.leftChar= L.leftChar;
        res.rightChar= R.rightChar;

        res.pre= L.pre;
        if(L.pre== leftLen && L.rightChar== R.leftChar){
            res.pre= L.pre + R.pre;
        }

        res.suf= R.suf;
        if(R.suf== rightLen && L.rightChar== R.leftChar){
            res.suf= L.suf + R.suf;
        }
        
        res.maxLen= max(L.maxLen, R.maxLen);
        if(L.rightChar== R.leftChar){
            res.maxLen= max(res.maxLen, L.suf + R.pre);
        }
        return res;
    }
    void update(int idx, int l, int r, int pos, char ch){
        if(l==r){
            seg[idx]= {1,1,1,ch,ch};
            return ;
        }
        int mid= l + (r-l)/2;

        if(pos <= mid){
            update(2*idx+1,l,mid,pos,ch);
        }else update(2*idx+2,mid+1,r,pos,ch);

        seg[idx]= merge(seg[2*idx+1],seg[2*idx+2], mid-l+1, r-(mid+1)+1);
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        n= s.length();
        seg.assign(4*n, Node());
        buildSeg(0,0,n-1,s);
        int k= queryIndices.size();
        vector<int>res(k);
        for(int i=0;i<k;i++){
            int pos= queryIndices[i];
            char ch= queryCharacters[i];
            update(0,0,n-1,pos,ch);
            
            res[i]= seg[0].maxLen;
        }
        return res;
    }
};

//TC-> o(n + k(log n))
//kuki har query update ka time log n hoga aur total queries h k
//aur segment tree build ka o(n) 

//SC-> o(n);
//Approach-> segment tree