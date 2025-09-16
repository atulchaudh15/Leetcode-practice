
// -> Cycle detection in a diected graph using dfs(dfs + recursion stack logic)
// -> Approach (depth-first search)
#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>&adj,int u,vector<bool>& vis, vector<bool>& inStack){
        vis[u]=true;
        inStack[u]=true;
        for(auto& v : adj[u]){
            //agr visited nhi h aur dfs cycle true bta ra h to return false
            if(vis[v]==false && dfs(adj,v,vis,inStack)){
                return true;
            //agr hmare current dfs wala stack m vo wala node h to cycle h bro pakka 
            } else if(inStack[v]==true){
                return true;
            }
        }
        //phir s reset kr diya inStack waale vector ko
        inStack[u]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        //ye edges matrix s directed graph waali adjacency matrix bnayi
        vector<vector<int>>adj(V);
        for(auto& e : edges){
            int u=e[0],v=e[1];
            adj[u].push_back(v);
        }
        
        //ek vector visited wala
        vector<bool>vis(V,false);
        //ek recursion logic wala ki jis dfas k liye call krre h us recursion k accor..
        vector<bool>inStack(V,false);
        //Graph k connceted components k liye
        for(int i=0;i<V;i++){
            //agr node visited b nhi h aur dfs b true de rha h to vo cycle h
            if(!vis[i] && dfs(adj,i,vis,inStack)) return true;
        }
        return false;
        
    }

//TC -> 0(V+E)
//SC -> 0(V+E)