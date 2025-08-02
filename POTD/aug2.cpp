#include <bits/stdc++.h>
using namespace std;

long long minCost(vector<int>& basket1, vector<int>& basket2) {
    map<int, int> freq;
    for (auto& num : basket1) freq[num]++;
    for (auto& num : basket2) freq[num]--;

    vector<int> vec;
    for (auto it = freq.begin(); it != freq.end(); ++it) {
        int val = it->first;
        int freq_diff = it->second;

        if (freq_diff % 2 != 0) return -1;
        for (int i = 0; i < abs(freq_diff) / 2; i++) {
            vec.push_back(val);
        }
    }

    sort(vec.begin(), vec.end());
    int min_fruit = min(*min_element(basket1.begin(), basket1.end()),
                        *min_element(basket2.begin(), basket2.end()));

    long long cost = 0;
    for (int i = 0; i < vec.size() / 2; i++) {
        cost += min(vec[i], 2 * min_fruit);
    }

    return cost;
}



//this question is based on greedy + sorting + two pointer + hashMap