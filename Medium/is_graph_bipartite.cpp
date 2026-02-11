
    //LEETCODE-> 785. Is Graph Bipartite?
#include<bits/stdc++.h>
using namespace std;

bool check(int node, vector<int> &color, vector<vector<int>>& graph){
        int n= graph.size();
        queue<int>q;
        color[node]= 0;
        q.push(node);
        while(!q.empty()){
            int node= q.front();
            q.pop();
            for(auto &it : graph[node]){
                //mtlb agar neighbour node color nhi h to
                if(color[it]==-1){
                    //usko color krdo with color opposite to 
                    //previous node
                    //for eg: if color[node]->1
                    //then color[it]->should be->0, and vice versa
                    color[it]= !color[node];
                    q.push(it);
                } 
                //mtlb agar already color h
                //aur neighbour it ka color same h with color of node
                else if(color[it]== color[node]){
                    //simply return false
                    //kuki vo graph bipartite na hove h, hehe
                    return false;
                }  
            }

        }
        //agar sb kch sahi h aur false return nhi hua h abhi tk to 
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        //altrernating color track krne k liye
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                //agar check function false oh gya to 
                //simply return false
                if(check(i,color,graph)==false){
                    return false;
                }
            }
        }
        //else mst true h
        return true;   
    }