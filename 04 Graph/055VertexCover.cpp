#include<bits/stdc++.h>
using namespace std;

// GFG - Vertex Cover (Approximate Algorithm) 

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


// GFG - Vertex Cover (Minimum Vertex Cover)

class Solution{ // Brute-Force
    int ans;
    vector<pair<int, int>> edge;
    int count(vector<int> &vertex){
        for(auto v: edge){
            if(vertex[v.first-1]==0 && vertex[v.second-1]==0)
                return ans;
        }
        int c = 0;
        for(auto v: vertex)
            c+=v;
        return c;
    }
    void subset(int i, vector<int> &vertex){
        if(i == vertex.size()){
            int val = count(vertex);
            ans = min(val, ans);
            return;
        }
        subset(i+1, vertex);
        vertex[i]=1;
        subset(i+1,vertex);
        vertex[i]=0;
    }
    public:
        int vertexCover(int n, vector<pair<int, int>> &edges) {
            edge = edges;
            vector<int> vertex(n, 0);
            ans = n;
            subset(0,vertex);
            return ans;
        }
};


class Solution{ // Binary Search
    vector<vector<int>> adj;
    bool isPossible(int n, int m, int mid){ // this function generates all possible subset of size = mid and check for possiblity
        
        int set = (1<<mid)-1; // initially assume first mid element is taken 
        // let say if n = 5 and mid = 2
        // then initial set = 00011 in binary whose value = 3
        // You need a greate understanding of bit-masking to understand the above explanation

        int limit = (1<<n); // maximum limit 
        // if n = 5
        // similary the set cannot be like greater than 11111 in binary 
        
        
        while(set<limit){
            
            bool vis[n + 1][n + 1] = {0}; // to store allready covered edges between (u, v)
            
            // vector<vector<int>> vis(n+1, vector<int>(n+1));
            // vector does not work because of internal complexity, and here the test case are strict
            
            int edgeCovered = 0; // To store no of edges can cover 
            
            for(int j = 1, u = 1; j<limit; j=j<<1, u++){
                if(set&j){
                    for(int v = 1; v<=n; v++){
                        if(adj[u][v] && !vis[u][v]){ // if edges between (u,v) && not visited;
                            edgeCovered++; // increment edgesCovered 
                            
                            // mark the edges to visited
                            vis[u][v] = 1;
                            vis[v][u] = 1;
                        }
                    }
                }
            }
            if(edgeCovered==m) // it is possible to cover all edges
                return true;
                
            // Below code is responsibele for generating permutation of setbits in set
            int rightMostSetBit = set & -set; // right most setBit of set
            int val= set+rightMostSetBit; 
            set = (((val^set)>>2)/rightMostSetBit)|val;
        }
        return false;
    }
    public:
        int vertexCover(int n, vector<pair<int, int>> &edges) {
            int m = edges.size();
            adj.resize(n+1,vector<int>(n+1));
            for(auto v: edges){
                adj[v.first][v.second]=1;
                adj[v.second][v.first]=1;
            }
            // Binary search
            int l = 1,r = n;
            while(l<r){
                int mid = (l+r)>>1;
                // if mid(number of vertex) is sufficient to cover all edge it mean that our ans is equal to mid OR in smaller than mid
                // else our ans is greater than mid
                if(isPossible(n, m, mid)){
                    r = mid;
                }else{
                    l = mid+1;
                }
            }
            // At end of loop => l == r
            // so we can return any one
            return l;
        }
};
