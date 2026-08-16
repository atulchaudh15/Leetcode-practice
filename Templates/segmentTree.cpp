#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
    int n;
    int build(int idx, int low,int high,vector<int>& seg, vector<int>& vec){
        //base case
        if(low == high){
            return seg[idx]= vec[low];
        }
        int mid= low +(high-low)/2;
        //making left node
        seg[2*idx+1]= build(2*idx+1, low, mid, seg, vec);
        //making right node
        seg[2*idx+2]= build(2*idx+2, mid+1, high, seg, vec);

        seg[idx]= min(seg[2*idx+1], seg[2*idx+2]);

    }

    int query(int idx, int low, int high, int left, int right, vector<int>& seg){
        //teen case honge 
        //no overlap , {left, right}[low, high]
        //             [low, high]{left, right}
        if(left < low && right > high){
            return INT_FAST32_MAX;
        }
        //complete overlap [low   {left, right}   high]
        if(left >= low && right <= high){
            return seg[idx];
        }
        //partial overlap

        int mid= low + (high - low)/2;
        
        int l= query(2*idx+1, low, mid, left, right, seg);
        int r= query(2*idx+2, mid+1, high, left, right, seg);

        return min(l,r);
        
    }

    void update(int idx, int low, int high, int i, int val, vector<int>& seg){
        if(low==high){
            seg[idx]=val;
            return ;
        }

        int mid= low + (high - low)/2;

        update(idx, low, mid, 2*i+1, val, seg);
        update(idx, low, mid, 2*i+2, val, seg);
        
        seg[idx]= min(seg[2*i+1], seg[2*i+2]);
    }
};

int main(){
    int n;
    vector<int>seg;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    seg.resize(4*n);

    


    return 0;
    
}