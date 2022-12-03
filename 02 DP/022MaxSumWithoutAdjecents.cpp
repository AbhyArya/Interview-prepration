#include<bits/stdc++.h>
using namespace std;

// GFG - Max Sum Without Adjacents

class Solution{
    int f(int i,int *arr, int n, vector<int>&dp){
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int untake = f(i+1, arr, n, dp);
        int take = arr[i] + f(i+2, arr, n, dp);
        return dp[i] = max(untake , take);
    }
public:
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n+1, -1);
	    return f(0,arr, n, dp);
	}
};