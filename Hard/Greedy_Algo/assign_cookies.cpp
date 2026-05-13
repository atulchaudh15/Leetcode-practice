
   //Leetcode-> 455. Assign Cookies

#include<bits/stdc++.h>
using namespace std;
int findContentChildren(vector<int>& g, vector<int>& s) {
        //solving it by greedy so that we can maximize the no. of children getting cookies
        // so it becomes sorting + assignment
        int n=g.size();
        int m=s.size();
        //two pointers for traversing both arrays
        int i=0,j=0;
        //count of children getting cookies
        int cnt=0;
        //sorting in order to get children with less greed factors comes first
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i<n && j<m){
            if(g[i] <= s[j]){
                cnt++;
                i++;
            }
            j++;
        }
        return cnt;
    }

//Approach-> sorting + greedy
//TC->o(n. longm + m. logm + m)
//SC->o(1)