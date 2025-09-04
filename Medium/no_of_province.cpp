
//  547. Number of Provinces (Started graph)

#include <bits/stdc++.h>
using namespace std;

void dfs(int start, vector<vector<int>>& adjLs, vector<int>& vis){
    vis[start]=1;
    for(auto& i : adjLs[start]){
        if(!vis[i]){
            dfs(i,adjLs,vis);
        }
    }
}
int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adjLs(n);
        vector<int>vis(n,0);
        
        //creating adjacency list
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        //counting no. of provinces
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjLs,vis);
            }
        }
        return cnt;
    }
