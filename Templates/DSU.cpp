#include <bits/stdc++.h>
using namespace std;
class DSU {
    vector<int> parent,rank;
public:
    DSU(int n){
    	parent.resize(n+1);
        rank.resize(n+1,0);

        for(int i=0;i<=n;i++){
            parent[i] =i;
        }
    }

    int find(int node) {
        if (node ==parent[node])
            return node;

        return parent[node] = find(parent[node]);
    }

    void Union(int x, int y){
	    int x_parent =find(x);
	    int y_parent =find(y);
	
	    if (x_parent ==y_parent) 
	        return;
	    if(rank[x_parent]< rank[y_parent]){
            parent[x_parent]= y_parent;
        }else if(rank[x_parent]> rank[y_parent]){
            parent[y_parent]= x_parent;
        }else{
            parent[x_parent]= y_parent;
            rank[y_parent]++;
        }
	}
};
int main() {
    DSU dsu(6);
    dsu.Union(0, 1);
    dsu.Union(0, 2);
    
    // if 0 and 3 are not on same Component yet
    if (dsu.find(0) == dsu.find(3)) {
        cout << "In same component" << endl;
    } else {
    	cout << "Not in same component" << endl;
    }
    
    //Now we will Union 0 and 3
    dsu.Union(0, 3);
    if (dsu.find(0) == dsu.find(3)) {
        cout << "In same component" << endl;
    } else {
    	cout << "Not in same component" << endl;
    }
}
