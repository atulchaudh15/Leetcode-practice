#include <bits/stdc++.h>
using namespace std;
int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
    int n = fruits.size();
    int res = 0, total = 0;
    int left = 0;

    for (int right = 0; right < n; ++right){
        total += fruits[right][1];

        while (left <= right){
            int l = fruits[left][0];
            int r = fruits[right][0];

            // Case 1: Go left first then right
            int dist1 = abs(startPos - l) + (r - l);
            // Case 2: Go right first then left
            int dist2 = abs(startPos - r) + (r - l);

            if (min(dist1, dist2) <= k)
                break; //valid window

            total -= fruits[left][1]; //shrink window from left
            ++left;
        }

        res = max(res, total);
    }

    return res;
}

//Approach-> Sliding window + Greedy algo
//TC -> 0(n)
//SC -> 0(1)
