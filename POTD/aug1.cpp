#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> generate(int numRows) {
        vector<int>vec;
        vector<vector<int>>ans;
        for(int i=0;i<numRows;i++){
            int val=1;
            for(int j=0;j<=i;j++){
                vec.push_back(val);
                val= val * (i-j) / (j+1);
            }
            ans.push_back(vec);
            vec.clear();
        }
        return ans;
    }

//TC-> 0(rowsNum)
//SC-> 0(rowsNum)