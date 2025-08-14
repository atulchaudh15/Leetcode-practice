#include <bits/stdc++.h>
using namespace std;
string largestGoodInteger(string num) {
        int n= num.size();
        //if no good integer then return empty string
        string str="";
        for(int i=0;i<=n-3;i++){
            if(num[i] == num[i+1] && num[i] == num[i+2]) {
               //this is a very useful method used for string handling
               //this method is used to form a string of desired length with same char
               // string name (desired length, char of which string should be made)
               string s(3,num[i]);
               str= max(str, s);
            }
        }
        return str;
    }

//TC -> 0(n)
//SC -> 0(1)