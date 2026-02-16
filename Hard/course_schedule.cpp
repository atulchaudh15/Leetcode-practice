
  //LEETCODE-> 207. Course Schedule

#include<bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //this ques is similar to topo sort beacuase in this ques
        //it says if we want course ai then firstly we have to take bi
        //similar to u then first v
        //making adjacency list
        vector<vector<int>> adjLs(numCourses);
        for(auto &p : prerequisites){
            //agar hme ai chahiye to pehle bi aana chahiye so, bi->ai
            adjLs[p[1]].push_back(p[0]);
        }
        //forming indegree vector
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto &it : adjLs[i]){
                indegree[it]++;
            }
        }
        //ye track krne k liye ki saare courses finish ho gye ya nhi
        int cnt=0;
        //ab jiska indegree 0 ho usko queue m push krdo
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                cnt++;
            }
        }
        //now simple bfs
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto &v : adjLs[u]){
                indegree[v]--;

                if(indegree[v]==0){
                    q.push(v);
                    cnt++;
                }
            }
        }
        //now at last checking for all courses
        if(cnt==numCourses) return true;
        else return false;

    }

//Approach-> topo sort using bfs
//TC-> 0(V+E)
//Explaination->
//forming adjacency list 
//0(V)
//forming indegree vector
//0(V)
// har node queue m sirf ek baar jayega
//0(V)
//aur har edge bhi sirf ek hi baar visit hogi ...throught for loop
//so 0(E)
//to total queue processing 0(V+E); in undirected it is 0(V+2E)

//Overall TC-> 0(V)+0(V)+0(V+E)

//SC-> 0(V+E)