

//Cycle detection using bfs traversal (Kahn's Algorithm)

#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int V, vector<vector<int>> &edges) {
        //forming directed graph from given edges matrix
        queue<int>q;
        vector<vector<int>>adj(V);
        for(auto& e : edges){
            int u=e[0],v=e[1];
            adj[u].push_back(v);
        }
        
        //forming indegree vector
        vector<int>indegree(V);
        for(int u=0; u<V; u++){
            for(auto& v : adj[u]){
                indegree[v]++;
            }
        }
        
        //filling queue used for bfs traversal
        int cnt=0;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
                cnt++;
            }
        }
        
        //simple bfs traversal
        while(!q.empty()){
            int u= q.front();
            q.pop();
            
            for(auto& v : adj[u]){
                indegree[v]--;
                
                if(indegree[v]==0){
                    q.push(v);
                    cnt++;
                }
            }
            
        }
        //ab agr saari node travel krli to mtlb cycle nhi h 
        if(cnt==V){
            return false;
        }
        //aur agr saari node cover ni hui to mtlb cycle h
        return true;
        
    }


//Approach -> bfs traversal
//TC -> 0(V * E)
//SC -> 0(V + E)