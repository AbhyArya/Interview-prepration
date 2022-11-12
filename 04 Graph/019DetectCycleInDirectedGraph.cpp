#include<bits/stdc++.h>
using namespace std;

// GFG - Detect Cycle in Directed Graph

class Solution {
    bool dfs(int src, vector<int> adj[], vector<int> &vis,vector<int> &stk){
        vis[src]=stk[src]=true;
        for(auto child: adj[src]){
            if(!vis[child]){
                if(dfs(child, adj, vis, stk))
                    return true;
            }else if(stk[child]){
                return true;
            }
        }
        stk[src]=false;
        return false;
    }
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V);
        vector<int> stk(V);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,stk))
                    return true;
            }
        }
        return false;
    }
};


// GFG - Using Kahn's Algorithms

class Solution {
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        int count = 0;
	    vector<int> indegre(V);
	    for(int i = 0; i<V; i++){
	        for(auto c: adj[i])
	            indegre[c]++;
	    }
	    queue<int> q;
	    for(int i = 0; i<V;i++){
	        if(!indegre[i]){
	            q.push(i);
	            count++;
	        }
	    }
	    while(!q.empty()){
	        int src = q.front();
	        q.pop();
	        for(auto child: adj[src]){
	            indegre[child]--;
	            if(!indegre[child]){
	                q.push(child);
	                count++;
	            }
	        }
	    }
	    return count!=V;
    }
};
