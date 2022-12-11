#include<bits/stdc++.h>
using namespace std;

// LeetCode - 300

class Solution{ // Memoization
    int f(int i,int prevIdx, int n,int a[], vector<vector<int>> &dp){
        if(i==n)
            return 0;
        if(dp[i][prevIdx+1] != -1)
            return dp[i][prevIdx+1];
        int untake = f(i+1, prevIdx, n, a,dp);
        int take = 0;
        if(prevIdx==-1 || a[prevIdx]<a[i])
            take = 1+f(i+1,i,n,a,dp);
        return dp[i][prevIdx+1] = max(take,untake);
    }
    public:
    int longestSubsequence(int n, int a[]){
       vector<vector<int>> dp(n,vector<int>(n+1, -1));
       return f(0,-1,n,a, dp);
    }
};



class Solution{ // Tabulation
    public:
    int longestSubsequence(int n, int a[]){
       int ans = 1;
       vector<int> dp(n,1);
       for(int i = 1; i<n; i++){
           for(int j = 0; j<i; j++){
               if(a[i]>a[j] && dp[i]<dp[j]+1)
                    dp[i] = dp[j]+1;
           }
           ans = max(ans, dp[i]);
       }
       return ans;
    }
};



class Solution{ // Using Binary Search
    public:
    int longestSubsequence(int n, int a[]){
       vector<int> list;
       list.push_back(a[0]);
       for(int i = 1; i<n; i++){
           auto it = lower_bound(list.begin(), list.end(), a[i]);
           if(it == list.end())
                list.push_back(a[i]);
            else
                *it = a[i];
       }
       return list.size();
    }
};





// GFG - Maximum sum increasing subsequence
class Solution{
	public:
	int maxSumIS(int arr[], int n)  {  
	    vector<int> dp(n);
	    int ans = 0;
	    for(int i = 0; i<n; i++){
    	    int sum = 0;
	        for(int j = 0; j<i; j++){
	            if(arr[i]>arr[j])
	                sum = max(sum, dp[j]);
	        }
	        dp[i] = arr[i]+sum;
	        ans = max(ans, dp[i]);
	    }
	    return ans;
	}  
};



// GFG - Printing Maximum Sum Increasing Subsequence
class Solution{
public:
    vector<int> maxSumSequence(int N, int A[]){
        vector<int>dp(N), parent(N);
        int ans = 0;
        int start=0;
        for(int i = 0; i<N; i++){
            int maxi = 0;
            int p = i;
            for(int j=0; j<i; j++){
                if(A[i]>A[j]){
                    if(maxi<dp[j]){
                        maxi = dp[j];
                        p = j;
                    }
                }
            }
            parent[i]=p;
            dp[i] = maxi + A[i];
            if(ans<dp[i]){
                ans = dp[i];
                start = i;
            }
        }
        vector<int> res;
        while(parent[start]!=start){
            res.push_back(A[start]);
            start = parent[start];
        }
        res.push_back(A[start]);
        reverse(res.begin(), res.end());
        return res;
    }
};