#include<bits/stdc++.h>
using namespace std;

// GFG - Unbounded Knapsack

class Solution{
    int f(int i, int w, int val[], int wt[],int n, vector<vector<int>>&dp){
        if(i==n || w == 0)
            return 0;
        if(dp[i][w]!=-1)
            return dp[i][w];
        int untake = f(i+1, w, val, wt, n, dp);
        int take = INT_MIN;
        if(w>=wt[i])
            take = val[i] + f(i, w-wt[i], val, wt, n, dp);
        return dp[i][w] = max(untake, take);
    }
public:
    int knapSack(int N, int W, int val[], int wt[]){
        vector<vector<int>>dp (N,vector<int>(W+1,-1));
        return f(0,W,val,wt,N,dp);
    }
};


// GFG - 0/1-Knapsack

class Solution{
    int f(int i, int w, int val[], int wt[],int n, vector<vector<int>>&dp){
        if(i==n || w == 0)
            return 0;
        if(dp[i][w]!=-1)
            return dp[i][w];
        int untake = f(i+1, w, val, wt, n, dp);
        int take = INT_MIN;
        if(w>=wt[i])
            take = val[i] + f(i+1, w-wt[i], val, wt, n, dp);
        return dp[i][w] = max(untake, take);
    }
    public:
    int knapSack(int W, int wt[], int val[], int n) { 
        vector<vector<int>>dp (n,vector<int>(W+1,-1));
        return f(0,W,val,wt,n,dp);
    }
};