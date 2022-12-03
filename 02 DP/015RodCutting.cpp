#include<bits/stdc++.h>
using namespace std;

// GFG - Rod Cutting

class Solution{
    int f(int i, int n, int price[], vector<vector<int>> &dp){
        if(n == 0)
            return 0;
        if(i<0)
            return -1e9;
        if(dp[i][n]!=-1)
            return dp[i][n];
        int ans = -1e9;
        ans = max(ans,f(i-1, n, price, dp));
        if(n>=i+1)
            ans = max(ans,price[i]+f(i,n-i-1,price, dp));
        return dp[i][n] = ans;
    }
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n,vector<int>(n+1, -1));
        int ans = f(n-1,n,price,dp);
        return ans;
    }
};