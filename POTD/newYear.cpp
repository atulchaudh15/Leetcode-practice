

  // Leetcode-> 66. Plus One

#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();

    for (int i = n - 1; i >= 0; i--) {
        //if the  last digit is less than 9 
        //just add 1 to it and simply return the vector 
        if (digits[i] < 9) {
            digits[i]++;
            return digits;
        }
        //if digit is 9 then make it 0
        digits[i] = 0;
    }

    // if all digits were 9
    digits.insert(digits.begin(), 1);
    return digits;
}

//TC-> 0(n)
//SC-> 0(n)