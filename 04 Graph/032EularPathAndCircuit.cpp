#include<bits/stdc++.h>
using namespace std;

// GFG - Euler circuit and Path - undirected graph

class Solution {
public:
	int isEularCircuit(int V, vector<int>adj[]){
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
	    return count == 0 || count == 2;;
	}
};

