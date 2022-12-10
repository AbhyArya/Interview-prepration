#include<bits/stdc++.h>
using namespace std;

// GFG - Binomial Coefficient
// GFG - Lob Number
class Solution{
    int mod = 1e9+7;
    int nCr(int n, int r,vector<vector<int>>& dp){
        if(r>n)
            return 0;
        if(n==r || r==0)
            return 1;
        if(dp[n][r]!=-1)
            return dp[n][r];
        return dp[n][r] = ((nCr(n-1, r-1,dp)%mod)+(nCr(n-1,r,dp)%mod))%mod;
    }
public:
    int nCr(int n, int r){
        vector<vector<int>> dp(n+1, vector<int>(r+1, -1));
        return nCr(n,r,dp);
    }
};