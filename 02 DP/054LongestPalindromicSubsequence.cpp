#include<bits/stdc++.h>
using namespace std;

// LeetCode - 516

class Solution {
    int f(int i, int j, string &s, vector<vector<int>> &dp){
        if(i>s.size() || j==0) 
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i-1]==s[j-1])
            return dp[i][j] = 1+f(i+1, j-1, s, dp);
        return dp[i][j] = max(f(i+1, j, s, dp), f(i, j-1, s, dp));
    }
public:
    int longestPalindromeSubseq(string s) {
        int n  = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        int ans = f(1,n,s,dp);
        return ans;
    }
};


// GFG - Print Longest Palindromic Subsequence
class Solution{   
public:
    string longestPalindrome(string s){
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(n+1,vector<int> (n+1));
        for(int i = n-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                if(s[i]==s[j]){
                    dp[i][j] = dp[i+1][j+1]+1;
                }else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        string ans = "";
        int i = 0;
        int j = 0;
        while(i<=n && j<=n){
            if(s[i]==t[i]){
                ans+=s[i];
                i++;
                j++;
            }else if(dp[i][j+1]>dp[i+1][j]){
                j++;
            }else{
                i++;
            }
        }
        return ans;
    }
};
