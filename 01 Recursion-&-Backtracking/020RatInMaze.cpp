#include<bits/stdc++.h>
using namespace std;

// GFG - Rat in Maze Problem

class Solution{
    void backtracking(int i, int j,string st, vector<vector<int>> &m,int n,vector<string> &ans){
        if(i<0 || j<0 || i>=n || j>=n || m[i][j]==0)
            return;
        if(i==n-1 && j == n-1){
            ans.push_back(st);
            return;
        }
        int val = m[i][j];
        m[i][j] = 0;
        backtracking(i+1,j,st+"D",m,n,ans);
        backtracking(i-1,j,st+"U",m,n,ans);
        backtracking(i,j-1,st+"L",m,n,ans);
        backtracking(i,j+1,st+"R",m,n,ans);
        m[i][j] = val;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        backtracking(0,0,"",m,n,ans);
        return ans;
    }
};