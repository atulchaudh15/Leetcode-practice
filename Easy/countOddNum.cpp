
    //Leetcode easy -> 1523. Count Odd Numbers in an Interval Range

#include <bits/stdc++.h>
using namespace std;
 int countOdds(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++){
            if(i%2 != 0){
                cnt++;
            }
        }
        return cnt;
    }

//TC -> O(n)
//SC -> O(n)
//Approach -> very easy, just iterate from low to high and check for for odd as simple as that no rocket science

