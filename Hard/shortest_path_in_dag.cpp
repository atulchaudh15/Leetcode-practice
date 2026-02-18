
  //LEETCODE-> Shortest path in DAG

#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int> &vis,stack<int>&st,vector<vector<pair<int,int>>>&adjLs){
        vis[node]=1;
        //pehle mere bachho ko daalo
        for(auto &v : adjLs[node]){
            int n= v.first;
            if(!vis[n]){
                dfs(n,vis,st,adjLs);
            }
        }
        //phir at last mujhe daalon
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<int>vis(V,0);
        stack<int>st;
        
        vector<vector<pair<int,int>>>adjLs(V);
        for(int i=0;i<E;i++){
            int u= edges[i][0];
            int v= edges[i][1];
            int wt= edges[i][2];
            adjLs[u].push_back({v,wt});
        }
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,st,adjLs);
            }
        }
        vector<int>dist(V,INT_MAX);
        dist[0]=0;
        while(!st.empty()){
            int u= st.top();
            st.pop();
            
            if(dist[u] != INT_MAX){
                for(auto &it : adjLs[u]){
                int v= it.first;
                int wt= it.second;
                if(dist[u] + wt < dist[v])
                    dist[v]= dist[u]+wt;
                }
                
            }
            
        }
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX)
            dist[i]=-1;
        }
        return dist;
            
    }

//Approach-> topo sort using dfs
//TC->0(V+E)
//SC->0(V+E)

//can be done using dijkstra's algo