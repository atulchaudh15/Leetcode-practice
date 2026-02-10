
  //GFG, Leetcode-> Number of Distinct Islands

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid,
    vector<pair<int,int>> &vec, int baseRow, int baseCol){
        int n= grid.size();
        int m= grid[0].size();
        vis[row][col]=1;
        vec.push_back({baseRow-row,baseCol-col});
        for(auto &dir : directions){
            int nrow= row + dir[0];
            int ncol= col + dir[1];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
            !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,vis,grid,vec,baseRow,baseCol);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid){
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    //making shape for 
                    vector<pair<int,int>>vec;
                    dfs(i,j,vis,grid,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
 