#include<bits/stdc++.h>
using namespace std;

//  GFG - Course Schedules

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<vector<int>> adj(n);
        for(auto v: prerequisites){
            adj[v[1]].push_back(v[0]);
        }
        vector<int> topo;
	    vector<int> indegre(n);
	    for(int i = 0; i<n; i++){
	        for(auto c: adj[i])
	            indegre[c]++;
	    }
	    queue<int> q;
	    for(int i = 0; i<n;i++){
	        if(!indegre[i])
	            q.push(i);
	    }
	    while(!q.empty()){
	        int src = q.front();
	        topo.push_back(src);
	        q.pop();
	        for(auto child: adj[src]){
	            indegre[child]--;
	            if(!indegre[child])
	                q.push(child);
	        }
	    }
	    if(topo.size() != n)
	        return {};
	    return topo;
    }
};