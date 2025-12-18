
// Leetcode -> 54. Spiral Matrix

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int top=0, bottom= matrix.size()-1;
        int left=0, right= matrix[0].size()-1;
        while(top<=bottom && left<=right){
            //first row
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            
            //right column
            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            //bottom row
            //edge case to verify if there is only one row
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[bottom][i]); 
                }
                bottom--;
            }
            //left row
            //edge case to verify if there is only one column
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                   ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }

//Approach -> Start from first row(as top) then 
            //go to last column(as right) 
            //then last row(as bottom) 
            //and at last first column(as left)
//TC -> O(row*col)
//SC -> O(no. of elements which is obviously row*col)