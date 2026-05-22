

    // Leetcode-> 210. Course Schedule II

#include<bits/stdc++.h>
using namespace std;

//important concept hm log ek global variable declare kr lenge
    bool isCycle=false;
    void dfs(int u,vector<vector<int>>&adjLs,vector<int>&vis,stack<int>&st,vector<int>&inRec){
        vis[u]=1;
        inRec[u]=1;
        for(auto& v : adjLs[u]){
            if(vis[v] && inRec[v]){
                //to mtlb cycle h aur agar cycle h to isCycle ko true krdo
                isCycle= true;
                return ;
            }
            //aur agar visited nhi h to dfs call krdo
            if(!vis[v]){
                dfs(v,adjLs,vis,st,inRec);
            }
        }
        //pehle mere bachho ko daalo phir mujhe daalo
        //topo sort order nikalne k liye
        st.push(u);

        //ab hm log cycle detection waale h inRec ko revert back kr denge
        inRec[u]=0;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjLs(numCourses);
        vector<int>vis(numCourses,0);
        vector<int>inRec(numCourses,0);
        stack<int>st;
        //making adjacency list
        for(auto&p : prerequisites){
            //[a,b], to edge hogi b->a
            adjLs[p[1]].push_back(p[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                dfs(i,adjLs,vis,st,inRec);
            }
        }

        //ab check kr lenge ki agar dfs k baad cycle h to mtlb saare course complete
        //nhi ho payenge
        if(isCycle) return {};

        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        
        return res;
    }

//Approach-> cycle detection + topo sort order using dfs
//TC->o(v+e), har node ek baar visit hogi aur har edge ek hi baar traverse krenge
//v-> numcourses
//e-> prerequisites.size()
//SC->o(v+e)+ auxilliary stack + o(V) + o(V)
