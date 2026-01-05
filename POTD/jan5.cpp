

   //LEETCODE-> 1975 (Maximum matrix sum)

#include<bits/stdc++.h>
using namespace std;

long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long negCnt=0;
        //counting no. of negative no...
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]<0) negCnt++;
            }
        }
        //calculating the absolute sum of all numbers in matrix
        long long sum=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                sum= sum+(abs(matrix[i][j]));
            }
        }
        //finding the smallest no. in the matrix
        long long minNo=LLONG_MAX;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
               minNo=min(minNo, (long long)abs(matrix[i][j])); 
            }
        }
        //no. of negative numbers is even
        return (negCnt%2==0)? sum: sum-(2*minNo);
    }

//Learning from this in case if we are using long long then we will use LLONG_MAX instead of INT_MAX
//ans finding absolute we need to add(long long)before absolute value to convert it into long long

//TC->0()
//SC->0()