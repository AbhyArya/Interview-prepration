#include<bits/stdc++.h>
using namespace std;

// GFG - BFS 

// For connected graph
class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> vis(V);
        queue<int> q;
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int parent = q.front();
            q.pop();
            ans.push_back(parent);
            for(auto child: adj[parent]){
                if(!vis[child]){
                    q.push(child);
                    vis[child] = true;
                }
            }
        }
        return ans;
    }
};



// For disconnected graph
class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> vis(V);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                queue<int> q;
                q.push(i);
                vis[i]=true;
                while(!q.empty()){
                    int parent = q.front();
                    q.pop();
                    ans.push_back(parent);
                    for(auto child: adj[parent]){
                        if(!vis[child]){
                            q.push(child);
                            vis[child] = true;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
