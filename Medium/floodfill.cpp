
  //733. Flood Fill (Graph)

#include <bits/stdc++.h>
using namespace std;
    //trick for 4-directional cells traversal
    vector<vector<int>> directions{{0,-1},{0,1},{-1,0},{1,0}};

    
    void dfs(int row, int col, vector<vector<int>>& temp, vector<vector<int>>& image, int& color, int& initColor){ 
        int n= image.size();
        int m= image[0].size();
        temp[row][col]= color;
        //colouring the neighbour
        for(auto& dir : directions){
            int nrow= row+ dir[0];
            int ncol= col+ dir[1];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
            image[nrow][ncol]== initColor && temp[nrow][ncol] != color){
                dfs(nrow,ncol,temp,image,color,initColor);
            } 
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initColor= image[sr][sc];
        vector<vector<int>> temp= image;
        dfs(sr,sc,temp,image,color,initColor);
        return temp;

    }

//Approach-> dfs traversal
//SC-> o(n*m)
//TC-> o(n*m)