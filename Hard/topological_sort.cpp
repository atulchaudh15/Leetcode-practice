
// -> Topological sort (Graph)

//Key Point-> topo sort is valid for directed acyclic graph only
//because we need an edge (u -> v) for topo sort and if the graph will be undirected we will
//not be able to figure out which node to be placed first 

#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>>&adj, vector<bool>& vis, stack<int>& st){
        vis[u]= true;
        
        //pehle u ki child nodes ko stack m daalo
        for(auto& v : adj[u]){
            if(!vis[v]){
                dfs(v,adj,vis,st);
            }
        }
        //ab u ko daalo khud
        st.push(u);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        //forming adjacency list from edges graph
        //stack for storing topo sort order
        stack<int>st;
        vector<vector<int>>adj(V);
        for(auto& e : edges){
            int u=e[0],v=e[1];
            adj[u].push_back(v);
        }
        vector<bool>vis(V,false);
        //connected component logic
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        //for returning topo sort answer
        vector<int>result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
           
        }
        return result;
    }


//Approach -> using Dfs traversal of the graph

//TC -> 0(V + E)
//SC -> 0(V + E)
