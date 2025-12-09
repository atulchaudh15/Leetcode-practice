
   //Leetcode easy -> 1925. Count Square Sum Triples

#include <bits/stdc++.h>
using namespace std;

int countTriples(int n) {
        int cnt=0;
        for(int a=1;a<=n;a++){
           for(int b=a+1;b<=n;b++){
              int s= (a*a)+ (b*b);
              int x= sqrt(s);
                if((x*x)==s && x<=n) cnt +=2;
           }
        }
       return cnt;
}

//TC -> O(n*2 * logn), due to two nested for loop * square root function
//SC -> O(1)
// Approach-> it is simple we have to take two number a,b between 1 to n and add the sq of both num and then then again
//squaring the sqrt value to check whether it is was a perfect sqaure and in range