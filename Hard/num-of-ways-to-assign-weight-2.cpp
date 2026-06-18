

  // LEETCODE 3559. Number of Ways to Assign Edge Weights II

#include<bits/stdc++.h>
using namespace std;

int M= 1e9+7;
    int rows;
    int cols;
    vector<vector<int>>ances;
    vector<int>depth;

    //saari node ki depth nikalne k liye
    void dfs(int root, int parent, vector<vector<int>>&adj){
        //agar hm root s ek jump maarenge upar to hm parent p hi to pahuch jaenge
        ances[root][0]= parent;
        for(auto &ngbr : adj[root]){
            if(ngbr==parent) continue;
            //mtln hm root p aaye h phir uske baad agar ek jump marenge to hm log
            //neighbour p pahuch jaenge
            //isliye root m plus 1 krdo bs 
            depth[ngbr]= depth[root]+1;

            dfs(ngbr, root, adj);
        }
    }
    //fill krenge ancestor table
    void ancesTable(){
        for(int j=1;j<cols;j++){
            for(int node=0;node<rows;node++){
                if(ances[node][j-1] != -1){
                    ances[node][j]= ances[ances[node][j-1]][j-1];
                }
            }
        }
    }
    //ab last hmko kisi u,v nodes ka common ances chahiye
    int LCA(int u, int v){
        //konsa node deeper depth p h
        //kuki simplicity k liye hmne u ko hi deep let kiya h
        if(depth[u]< depth[v]){
            swap(u,v);
        }
        //ab hm calculate krenge ki u kitna deeper h v s
        int k= depth[u]-depth[v];
        for(int j=0;j<cols;j++){
            if(k & (1 << j)){
                u= ances[u][j];

            }
        }
        if(u==v){
            //agar u aur v dono same path p hai
            return u;
        }
        //wrna hm log  j jump krnaa start krenge
        for(int j=cols-1;j>=0;j--){
            //agar possible nhi h utna jump to skip krdo
            if(ances[u][j] == -1){
                continue;
            }
            //ab hm check krenge ki ky dono ek ki depth p pahuch gye h ya nhi agar nhi to hm log jump krate rhenge
            if(ances[u][j] != ances[v][j]){
                u= ances[u][j];
                v= ances[v][j];
            }
        }
        //jb hm yhn p pahuch jaenge to ye dono lca k just neeche waali node p honge
        return ances[u][0];
    } 
    
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int len= edges.size()+1;
        rows= len;
        cols= log2(len)+1;
        vector<int>res;
        ances.resize(rows, vector<int>(cols,-1));
        vector<vector<int>>adj(len+1);
        for(auto &e : edges){
            int u= e[0]-1;
            int v= e[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //depth nikalna h sbka
        depth.resize(len+1);
        
        //dono dfs aur ances ko call krdo
        dfs(0,-1,adj);
        ancesTable();

        //precompute 2 ki power
        vector<int>pow2(len+2);
        pow2[0]=1;
        for(int j=1;j<len;j++){
            pow2[j]= (2LL * pow2[j-1])%M;
        } 
        for(auto &q : queries){
            int u= q[0]-1;
            int v= q[1]-1;

            int d= depth[u] + depth[v] - 2*depth[LCA(u,v)];

            if(d==0){
                //mtlb same node h 
                //to res m 0 push krdo
                res.push_back(0);
            }else{
                res.push_back(pow2[d-1]);
            }
 
        }
        return res;
    }