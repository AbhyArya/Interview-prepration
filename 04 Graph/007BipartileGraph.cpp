#include<bits/stdc++.h>
using namespace std;

// LeetCode - 785

class Solution {
    bool isBipar(int node,int col, vector<vector<int>>& adj, vector<int> &color){
        color[node] = col;
        for(auto child: adj[node]){
            if(color[child]==-1){
                if(!isBipar(child, !col, adj, color))
                    return false;
            }else if(color[child]==col){
                return false;
            }
        }
        return true;
    }
public:
	bool isBipartite(vector<vector<int>>& adj){
        int V = adj.size();
	    vector<int> color(V,-1);
	    for(int i = 0; i<V; i++){
	        if(color[i]==-1){
	            if(!isBipar(i,0,adj,color))
	                return false;
	        }
	    }
	    return true;
	}
};