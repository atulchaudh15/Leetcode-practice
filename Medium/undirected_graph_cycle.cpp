

// -> Undirected graph cycle detection by bfs

#include <bits/stdc++.h>
using namespace std;
bool bfs(vector<vector<int>>& adj, int u, vector<bool>& vis){
        queue<pair<int,int>>q;
        q.push({u,-1});
        vis[u]= true;
        while(!q.empty()){
            int temp= q.front().first;
            int parent= q.front().second;
            q.pop();
            for(auto& v : adj[temp]){
            //agar visited nhi h to visit kro
            if(vis[v]==false){
                vis[v]=true;
                q.push({v,temp});
            }
            //else agar vo already visited h aur parent nhi h to mtlb bhai cycle h
            else if(v != parent) return true;
        }
        }
        //ab last h agr vo visited h aur parent b nhi h tbhi for loop s bahar aayega control 
        //to return kr denge false
        return false;
        
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        //ye edge s adjacency matrix bna rhe h 
        vector<vector<int>>adj(V);
        for(auto& e : edges){
            int u=e[0],v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(V,false);
        //aur ye graph k connected components solve krne k liye for loop 
        for(int i=0;i<V;i++){
            //agr visited b nhi h aur bfs true return krta h to cycle h 
            if(!vis[i] && bfs(adj,i,vis)){
                return true;
            }
        }
        return false;
    }


//TC -> 0(V + E)
//SC -> 0(V + E), kuki graph s adjacency list bnayi h 