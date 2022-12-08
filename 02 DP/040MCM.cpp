#include<bits/stdc++.h>
using namespace std;

// GFG - MCM

class Solution{
    int f(int s, int e, int arr[], vector<vector<int>> &dp){
        if(s == e)
            return 0;
        if(dp[s][e]!=-1)
            return dp[s][e];
        int ans = 1e9;
        for(int i = s; i<e; i++){
            int val = arr[s-1]*arr[i]*arr[e] + f(s, i, arr, dp) + f(i+1,e,arr, dp);
            ans = min(ans, val);
        }
        return dp[s][e] = ans;
    }
public:
    int matrixMultiplication(int N, int arr[]){
        vector<vector<int>> dp(N, vector<int>(N,-1));
        return f(1,N-1,arr, dp);
    }
};