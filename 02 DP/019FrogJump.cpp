#include<bits/stdc++.h>
using namespace std;

// GFG - Count Number of Hops

class Solution{
    int mod = 1e9+7;
    int f(int i,vector<int> &dp){
        if(i<=0){
            return i == 0;
        }
        if(dp[i]!=-1)
            return dp[i];
        long long ans = 0;
        for(int j = 1; j<4; j++){
            ans += f(i-j,dp);
            ans %= mod;
        }
        return dp[i] = (int)ans;
    }
    public:
    long long countWays(int n){
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};
