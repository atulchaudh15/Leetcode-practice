#include <bits/stdc++.h>
using namespace std;

int minSteps(int n) {
    vector<int> dp(n + 1, 1e9);
    dp[1] = 0; //for showing one 'a' on the screen we need 0 operations because it is (already written on screen)

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                int k = i / j;
                dp[i] = min(dp[i], dp[j] + 1 + (k - 1)); // copy + k-1 pastes
            }
        }
    }

    return dp[n];
}

//TC -> 0(n^2)
//SC -> 0(n+1)