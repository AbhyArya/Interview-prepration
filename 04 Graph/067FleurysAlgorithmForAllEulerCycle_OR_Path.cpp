#include<bits/stdc++.h>
using namespace std;

// GFG - Fleurys Algorithm

class Solution{
    int isEularCircuit(int V, vector<vector<int>> &adj){
	    vector<int> indegre(V);
	    for(int i = 0; i<V; i++){
	        for(auto child: adj[i]){
	            indegre[child]++;
	        }
	    }
	    bool isCycle = true;
	    int count = 0;
	    for(auto c: indegre){
	        if(c&1){
	            isCycle = false;
	            count++;
	        }
	    }
	    if(isCycle)
	        return 2;
	    return count == 0 || count == 2;
	}
    int dfs(int src, vector<vector<int>> &adj, vector<bool> &vis){
        vis[src]=true;
        int ans = 1;
        for(auto child: adj[src]){
            if(!vis[child]){
                ans+=dfs(child, adj,vis);
            }
        }
        return ans;
    }
    void removeEdge(int src, int dest, vector<vector<int>> &adj){
        auto pos1 = find(adj[src].begin(),adj[src].end(),dest);
        auto pos2 = find(adj[dest].begin(),adj[dest].end(),src);
        *pos1 = *pos2 = -1;
    }
    void addEdge(int src, int dest, vector<vector<int>> &adj){
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }
    bool isValid(int src, int dest, vector<vector<int>>&adj){
        int count = 0;
        for(auto child: adj[src]){
            if(child!=-1)
                count++;
        }
        if(count==1)
            return true;
        int n = adj.size();
        vector<bool> vis(n);
        int count1 = dfs(src,adj,vis);
        removeEdge(src,dest,adj);
        vis.clear();
        vis.resize(n);
        int count2 = dfs(src,adj,vis);
        addEdge(src,dest,adj);
        return count2==count1;
    }
    void eulerPath(int src, vector<vector<int>>&adj, vector<vector<int>> &ans){
        for(auto child: adj[src]){
            if(child!=-1 && isValid(src,child,adj)){
                ans.push_back({src,child});
                removeEdge(src,child,adj);
                eulerPath(child,adj,ans);
            }
        }
    }
    vector<vector<int>> getEulerTour(int n, vector<vector<int>> &adj){
        int start = 0;
        for(int i = 0; i<n; i++){
            if(adj[i].size()&1){
                start = i;
                break;
            }
        }
        vector<vector<int>> ans;
        eulerPath(start,adj,ans);  
        return ans;
    }
    vector<vector<int>> Eular(int n,vector<vector<int>> &adj){
        int isEular = isEularCircuit(n,adj);
        if(!isEular)
            return {};
        return getEulerTour(n,adj);
    }
};