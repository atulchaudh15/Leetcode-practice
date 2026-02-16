
// -> Topological sort using bfs traversal (also known as Kahn' Algorithm)

//Approach ->

// Step 1 -> forming indegree vector to count the number of incoming nodes (i.e. indegree)
// Step 2 -> filling queue with node whose indegree is zero
// Step 3 -> Simple bfs traversal of graph


#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<vector<int>>& edges) {
        //forming directed graph from edges
        vector<vector<int>>adj(V);
        for(auto& e : edges){
            int u=e[0],v=e[1];
            adj[u].push_back(v);
        }
        // Step 1 -> forming indegree vector to count the number of incoming nodes (i.e. indegree)
        vector<int>indegree(V,0);
        for(int u=0;u<V;u++){
            for(auto& v : adj[u]){
                indegree[v]++;
            }
        }
        // Step 2 -> filling queue with node whose indegree is zero
        queue<int>que;
        for(int i=0;i<V;i++){
                if(indegree[i]==0){
                    que.push(i);
                }
            }
        vector<int>result;
        // Step 3 -> Simple bfs traversal of graph
        while(!que.empty()){
            int temp= que.front();
            result.push_back(temp);
            que.pop();
            
            for(auto& v : adj[temp]){
                indegree[v]--;
                if(indegree[v]==0){
                    que.push(v);
                }
            }
            
        }
        return result;
    }

//TC -> 0(V + E)
//SC -> 0(V + E)