#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices){
    int n= prices.size();
    //starting index k liye minimun cost 0th waali hgi hogi
    int mini_buy_cost= prices[0];
    //max profit 0 hi hoga let kr liya
    int max_profit=0;
    for(int i=1;i<n;i++){
        //profit at ith index will be (selling cost of that index - 
        //minimun cost of buying from 0th index to i-1th index)

        int ith_index_profit= prices[i]- mini_buy_cost;
        max_profit= max(max_profit, ith_index_profit);
        mini_buy_cost= min(mini_buy_cost, prices[i]);

    }
    //returning max profit of full prices vector
    return max_profit;
    }