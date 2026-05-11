#include<bits/stdc++.h>
using namespace std;
vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n= nums.size();
        multiset<int>ms;
        vector<int>res;
        int i=0,j=0;
        while(j<n){
            if(nums[j]<0){
                ms.insert(nums[j]);
            }
            //agar window size reach ni hui to j ko ++ krte jao
            if(j-i+1 < k ){
                j++;
            }
            else if(j-i+1 == k){
                //smallest element de dega
                //ab isko x-1 tk chla do
                //aur hn important check ki agar mtlb x element hi nhi huye multiset m to 0 
                //store krna h
                if(ms.size() < x){
                    res.push_back(0);
                }
                else{
                    //smallest hoga pehla wala 
                    auto it= ms.begin();
                    advance(it,x-1);
                    //xth smallest value ko res m push krdo
                    //agar iterator result aaya h to usko store krne k liye dereference krdo 
                    //mtlb vo jis value ko point kr rha h 
                    //uski uski value nikal lo(store krlo * ka use krke) 
                    res.push_back(*it);
                }
                //ab window slide krne s pehle prev ith element agar hmare multiset
                //m present h to usko remove krdo
                if(ms.find(nums[i]) != ms.end()){
                    //all occurences nhi delete krni h to (find + delete)
                    ms.erase(ms.find(nums[i]));
                }
                //aur window slide krdo
                i++;
                j++;
            }
        }
        return res;
    }

//SC->o(n-k+1), size of multiset
//TC->o(n(logk+x))

/*Har window pe:
insert/remove:
O(logk)
x-th traversal:
O(x)
Total windows:
(n−k+1)
So overall:
O(n(logk+x))
Worst case:
O(nk)

*/