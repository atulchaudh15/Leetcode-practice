#include <bits/stdc++.h>
using namespace std;
//Recursive approach
    bool isPowerOfThree(int n) {
        if(n==1) return true;
        if(n<1 || n % 3 != 0) return false;
        return isPowerOfThree(n/3);
    }
    //Iterative approach
    bool isPowerOfThree(int n) {
       if(n<1) return false;
       while(n % 3 == 0){
          n /= 3;
       }
       return n==1;
    }

//Learned both methods recursive as well as iterative

//TC -> 0(n)
//SC -> 0(n), Auxiliary space