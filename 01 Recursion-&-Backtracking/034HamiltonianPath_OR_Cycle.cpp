#include<bits/stdc++.h>
using namespace std;

// GFG - Hamiltonian Cycle 
class Solution{
    bool isSafe(int curNode, int pos, vector<int> &path,vector<unordered_set<int>> &adj){
        if(adj[path[pos-1]].find(curNode)==adj[path[pos-1]].end())
            return false;
        for(int i = 0; i< pos; i++){
            if(path[i]==curNode)
                return false;
        }
        return true;
    }
    bool hamiltonianCycle(int pos, vector<int> &path,vector<unordered_set<int>> &adj){
        if(pos == path.size()){
            adj[pos-1].find(0)!=adj[pos-1].end();
        }
        for(int i = 1; i<path.size(); i++){
            if(isSafe(i,pos,path,adj)){
                path[pos] = i;
                if(hamiltonianCycle(pos+1, path, adj))
                    return true;
                path[pos] = -1;
            }
        }
        return false;
    }   
    public:
    bool check(int n,int m,vector<vector<int>> Edges)
    {
        vector<unordered_set<int>> adj(n);
        for(auto v: Edges){
            adj[v[0]-1].insert(v[1]-1);
            adj[v[1]-1].insert(v[0]-1);
        }
        vector<int> path(n,-1);
        path[0]=0;
        return hamiltonianCycle(1,path,adj);
    }
};




// GFG - Hamiltonian path
class Solution{
    bool hamiltonianPath(int src, int count,vector<bool> &vis,vector<vector<int>> adj){
        if(count == vis.size())
            return true;
        vis[src] = true;
        for(auto child: adj[src]){
            if(!vis[child] && hamiltonianPath(child,count+1,vis,adj)){
                return true;
            }
        }
        vis[src] = false;
        return false;
    }    
    public:
    bool check(int n,int m,vector<vector<int>> Edges){
        vector<vector<int>> adj(n);
        for(auto v: Edges){
            adj[v[0]-1].push_back(v[1]-1);
            adj[v[1]-1].push_back(v[0]-1);
        }
        for(int i = 0; i<n; i++){
            vector<bool> vis(n,false);
            if(hamiltonianPath(i,1,vis,adj))
                return true;
        }
        return false;
    }
};