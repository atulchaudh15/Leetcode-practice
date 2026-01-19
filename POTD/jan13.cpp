
  // Leetcode-> 3453. Separate Squares I

#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>>& squares, double mid, double total){
        double botArea=0.0;
        for(auto& sq: squares){
            double y= sq[1];
            double len= sq[2];
            
            double bot_y= y;
            double top_y= y+len;
            if(mid <= bot_y) continue;
             else if(mid >= top_y){
                //take full bottom area
                //i.e. poora sq lenge
                botArea += len*len;
            } else{
                //wrna partial area lenge sq ka
                botArea += (mid-bot_y)*len;
            }

        }
        //agar bottom area jyada h ya equal h
        return botArea >= total/2.0; 

    }
    double separateSquares(vector<vector<int>>& squares) {
        //binary search on ans
        double low= 1e18;
        double high= -1e18;
        double total= 0.0;

        for(auto& sq: squares){
            double y= sq[1];
            double len= sq[2];
            total += len*len;
            low= min(low,y);
            high= max(high,y+len);
        }

        while(high-low > 1e-5){
            double mid= low + (high-low)/2;
            if(check(squares,mid,total)){
                high= mid;
            }else{
                low= mid;
            }
        }
        return high;
    }

//Approach-> Binary search on answer
//TC->0(n* log(high-low)) , n for check function and logn for basic bs
//SC->0(1)