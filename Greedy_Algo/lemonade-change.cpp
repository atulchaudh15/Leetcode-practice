
  //Leetcode-> 860. Lemonade Change

#include<bits/stdc++.h>
using namespace std;
bool lemonadeChange(vector<int>& bills) {
        int n= bills.size();
        int cnt5=0,cnt10=0;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                cnt5++;
            }
            else if(bills[i]==10){
                if(cnt5==0) return false;
                else{
                    cnt10++;
                    cnt5--;
                }
            }else {
               if(cnt5 && cnt10){
                cnt5--;
                cnt10--;
               }
               else if(cnt5 >=3){
                cnt5= cnt5-3;
               }else {
                return false;
               }
            }
        }
        return true;
    }

//TC->o(n long n)
//SC->o(1)