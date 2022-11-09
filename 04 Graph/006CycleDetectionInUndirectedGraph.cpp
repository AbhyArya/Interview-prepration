#include<bits/stdc++.h>
using namespace std;

// GFG - Cycle Detection in Undirected graph
// DFS
class Solution {
    bool isCycle(int node, int parent, vector<int> adj[], vector<bool> &vis){
        vis[node]=true;
        for(auto child: adj[node]){
            if(!vis[child]){
                if(isCycle(child,node,adj,vis))
                    return true;
                }
            else if(child!=parent)
                return true;
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(isCycle(i,-1,adj,vis))
                    return true;
            }
        }
        return false;
    }
};


// BFS
class Solution {
  public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                queue<pair<int,int>> q;
                q.push({i,-1});
                vis[i]=true;
                while(!q.empty()){
                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();
                    for(int child: adj[node]){
                        if(!vis[child]){
                            q.push({child,node});
                            vis[child] = true;
                        }else if(child!=parent){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};