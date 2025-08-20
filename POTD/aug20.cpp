

//1277. Count Square Submatrices with All Ones


#include <bits/stdc++.h>
using namespace std;

int countSquares(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m,0));

        //filling first row
        for(int j=0;j<m;j++) dp[0][j]= matrix[0][j];
        //filling first column
        for(int i=0;i<n;i++) dp[i][0]= matrix[i][0];
        
        //filling rest dp table
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0) dp[i][j]=0;
                else{
                    dp[i][j]= 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});

                }
            }
        }
        //calculate the sum of whole dp table
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum += dp[i][j];
            }
        }
        return sum;
    }


//Approach -> Dp on rectangles
//TC -> o(n*m), where n,m are the number of rows and columns in the given matrix
//SC -> o(n*m), size of dp matrix