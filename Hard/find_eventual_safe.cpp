
    //LEETCODE-> 802. Find Eventual Safe States

#include<bits/stdc++.h>
using namespace std;

/*bool dfs(int node,vector<int> &vis,vector<int> &curr,vector<vector<int>> &graph){
        vis[node]=1;
        curr[node]=1;
        for(auto &v : graph[node]){
            if(!vis[v] && dfs(v,vis,curr,graph)){
                return true;
            }else if(curr[v]==true){
                return true;
            }
        }
        curr[node]=0;
        return false;
    } */
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V= graph.size();
        vector<vector<int>> adjLs(V);
        vector<int>indegree(V,0);
        vector<bool>vis(V,false);
        vector<int>res;
        queue<int>q;
        //making a copy of graph to with reverse edges
        for(int u=0;u<V;u++){
            //u->v
            for(auto &v : graph[u]){
                //v->u
                adjLs[v].push_back(u);   
            }
        }
        //forming indegree vector
        for(int i=0;i<V;i++){
            for(auto &it : adjLs[i]){
                indegree[it]++;
            }
        }
        //jiski indegree 0 ho usko push krdo queue m
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        //simple bfs
        while(!q.empty()){
            int u= q.front();
            q.pop();
            vis[u]=true;
            for(auto &v : adjLs[u]){
                indegree[v]--;

                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        for(int i=0;i<V;i++){
            if(vis[i]) res.push_back(i);
        }
        return res;
    }

//Appproach-> dfs, bfs cycle detection ka use kiya h with a little tweak
//TC->0(V+E)
//SC->0(V+E)