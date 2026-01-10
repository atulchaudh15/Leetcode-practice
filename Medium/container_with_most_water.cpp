
//11. Container With Most Water

#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
        //two pointer approach
        int i=0;
        int j=height.size()-1;
        int minArea=INT_MIN;
        while(i<j){
           //height will be min height of both tower
           int h=min(height[i],height[j]);
           //breadth will be diff bw j and i
           int b=j-i;
           int area=h*b;
           //calculating max area
           minArea=max(minArea,area);
           //shifting pointer
           if(height[i]<height[j]) i++;
           else j--;
        }
        return minArea;
    }

//Approach-> Greedy or two pointer
//TC->0(n)
//SC->0(1)