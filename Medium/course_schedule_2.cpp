
  //LEETCODE-> 210. Course Schedule II

#include<bits/stdc++.h>
using namespace std;
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjLs(numCourses);
        vector<int>indegree(numCourses,0);
        queue<int>q;
        //making adjacency list
        for(auto &p : prerequisites){
            //because to take ai we need to take bi first
            //so it makes bi->ai
            adjLs[p[1]].push_back(p[0]);
        }
        //forming indegree
        for(int i=0;i<numCourses;i++){
            for(auto &it : adjLs[i]){
                indegree[it]++;
            }
        }
        //jiska indegree 0 h queue m push krdo
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        //res vector to store topo sort
        vector<int>res;
        while(!q.empty()){
            int u= q.front();
            res.push_back(u);
            q.pop();

            for(auto &v : adjLs[u]){
                indegree[v]--;

                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        //isme bhi thoda sa tweak h kuki isme simply hm log order directly
        // return nhi kr skte ki jitni nodes process hui h utin node wla order hi return krod
        //nhi esa ni kr skte
        //isme agar saari nodes process ho gyi h tbhi return kro
        //agar ek bhi node km process hui h to vo mt return kro empty vector return kro
        if(res.size()==numCourses) return res;
        else return {};
    }

//Approach-> topo sort using bfs
//TC-> 0(V+E)
//SC-> 0(V+E)