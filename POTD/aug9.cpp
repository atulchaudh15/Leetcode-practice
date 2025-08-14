#include <bits/stdc++.h>
using namespace std;
//Iterative approach
    bool isPowerOfTwo(int n) {
        if(n<1) return false;
        while(n % 2 == 0){
            n /=2;
        }
        return n==1;
    }
//Recusive Approach
    bool isPowerOfTwo(int n) {
        if(n==1) return true;
        if(n<1 || n % 2 != 0) return false;
        return isPowerOfTwo(n/2);
    }

//TC -> 0(1)
//SC -> 0(1), and if recursion used then 0(n)