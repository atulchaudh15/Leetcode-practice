
   // Leetcode-> 994. Rotting Oranges
 
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>directions{{0,-1},{0,1},{-1,0},{1,0}};

    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        queue<tuple<int,int,int>>q;
        int freshCnt=0;
        //multi source bfs initialization
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }else if(grid[i][j]==1){
                    freshCnt++;
                }
            }
        }
        int maxi=0;
        //multi source bfs
        while(!q.empty()){
            auto [r,c,t]= q.front();
            maxi=max(maxi,t);
            q.pop();
            for(auto &dir : directions){
                int nrow= r+ dir[0];
                int ncol= c+ dir[1];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                && grid[nrow][ncol] ==1){
                    grid[nrow][ncol]=2;
                    freshCnt--;
                    q.push({nrow,ncol,t+1});
                }
            }
        }

        if(freshCnt==0){
           return maxi;
        } else return -1; 
    }

//Approach-> Used multi source bfs
//TC->0(V+E)
//SC->0(V)

//This ques is very good in order to understand multi source bfs technique in graph
//This ques also tells why can't we use dfs in these type of ques
