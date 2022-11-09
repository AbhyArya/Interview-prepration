#include<bits/stdc++.h>
using namespace std;

// GFG - DFS
// For connected graph
class Solution {
    void dfs(int node, vector<int> adj[],vector<bool> &vis, vector<int> &ans){
        ans.push_back(node);
        vis[node] = true;
        for(auto child: adj[node]){
            if(!vis[child]){
                dfs(child, adj, vis, ans);
            }
        }
    }
  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> vis(V);
        dfs(0, adj,vis, ans);
        return ans;
    }
};


// For disconnected graph
class Solution {
    void dfs(int node, vector<int> adj[],vector<bool> &vis, vector<int> &ans){
        ans.push_back(node);
        vis[node] = true;
        for(auto child: adj[node]){
            if(!vis[child]){
                dfs(child, adj, vis, ans);
            }
        }
    }
  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> vis(V);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj,vis, ans);
            }
        }
        return ans;
    }
};