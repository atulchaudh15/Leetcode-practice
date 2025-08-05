#include <bits/stdc++.h>
using namespace std;

int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n= fruits.size();
        vector<bool>vis(n,false);
        int unplaced=0;
        for(int i=0;i<n;i++){
            bool placed= false;
            for(int j=0;j<n;j++){
                if(!vis[j] && fruits[i]<=baskets[j]){
                    vis[j]=true;
                    placed=true;
                    break;
                }
            }
            if(!placed) unplaced++;
        }
        return unplaced;
    }

//Approach-> Simple and smart traversal
//TC -> 0(n*2)
//SC -> 0(n), using visited vector of size n