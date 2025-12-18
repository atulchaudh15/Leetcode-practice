
   //Leetcode -> Rotate Image

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
        //okay so to rotate an image by 90 degree clockwise
        //follow a simple trick
        // Firstly-> swap the element of upper triangle only( don't swap whole matrix 
        //, as it can nullify the swap effect)
        int row= matrix.size();
        int col= matrix[0].size();
        for(int i=0;i<row;i++){
            for(int j=i+1;j<col;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // Secondly-> reverse the matrix row wise( simply reverse each row)
        for(int i=0;i<col;i++){
           reverse(matrix[i].begin(), matrix[i].end());
        }
    }

//TC-> O(row*col);
//SC-> O(1);
