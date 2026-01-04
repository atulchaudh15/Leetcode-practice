
  // Leetcode-> 1390. Four Divisors

#include <bits/stdc++.h>
using namespace std;

int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(auto& num: nums){
            vector<int>res;
            //calculating factors of a number  
            for(int i=1;i*i<=num;i++){
                if(num%i ==0){
                    res.push_back(i);
                    //if the factor is diff from itself then put both in 
                    //the vector
                    if(i != num/i){
                        res.push_back(num/i);
                    }
                }
            }
            //if the number has exactly 4 factors
            if(res.size()==4){
                for(auto& it: res){
                    //then sum it and return it
                    sum +=it;
                }
            }
        }
        return sum;
    }

//TC-> 0(n*n)
//SC-> 0(n* factors of each numbers(max->n))=0(n*n)