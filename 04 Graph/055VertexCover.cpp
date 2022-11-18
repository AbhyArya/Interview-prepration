#include<bits/stdc++.h>
using namespace std;

// GFG - Vertex Cover

class Solution{
    vector<int> vertexCover(vector<vector<int>> &adj){
        int n = adj.size();
        vector<int> ans;
        vector<bool> vis(n);
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                for(auto child: adj[i]){
                    if(!vis[child]){
                        vis[i]=vis[child]=true;
                        break;
                    }
                }
            }
        }
        for(int i = 0;i<n; i++){
            if(vis[i])
                ans.push_back(i);
        }
        return ans;
    }
};