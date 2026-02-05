
  // 200. Number of Islands

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>directions{{0,-1},{0,1},{-1,0},{1,0}};


    
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        
        for(auto & dir : directions){
                int nrow= row+ dir[0];
                int ncol= col+ dir[1];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                vis[nrow][ncol]==0 && grid[nrow][ncol]=='1'){
                    dfs(nrow,ncol,vis,grid);
                }
            }
          
    }
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vis[row][col]=1;
        q.push({row,col});
        while(!q.empty()){
            int r= q.front().first;
            int c= q.front().second;
            q.pop();
            for(auto & dir : directions){
                int nrow= r+ dir[0];
                int ncol= c+ dir[1];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                vis[nrow][ncol]==0 && grid[nrow][ncol]=='1'){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
          
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }

//Approach-> dfs,bfs
//TC-> 0(n)+0(2E) , no. of degrees
//SC-> 0(n)

//Questions such as:

//Number of islands
//number of provinces
//Number of connected components

//These all are based on only one concept which is  no. of connected components in a graph(or of a graph)