#include<bits/stdc++.h>
using namespace std;

// LeetCode - 877

class Solution {
    int f(int s, int e, bool alice,vector<int>& piles,vector<vector<vector<int>>> &dp){
        if(s>e)
            return 0;
        if(dp[s][e][alice]!=-1)
            return dp[s][e][alice];
        if(alice){
            int start = piles[s] + f(s+1,e,false,piles,dp);
            int end = piles[e] + f(s,e-1,false,piles,dp);
            return dp[s][e][alice] = max(start,end);
        }else{
            int start = f(s+1,e,false,piles,dp);
            int end = f(s,e-1,false,piles,dp);
            return dp[s][e][alice] = min(start,end);
        }
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int sum = accumulate(piles.begin(),piles.end(), 0);
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        int ans = f(0,n-1,true,piles,dp);
        return ans > 0;

    }
};