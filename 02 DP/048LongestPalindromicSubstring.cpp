#include<bits/stdc++.h>
using namespace std;

// LeetCode - 5

class Solution {
    void updateAns(int left, int right,int n,string &ans,string &s){
        int len = 0;
        while(left>=0 && right<n && s[left]==s[right]){
            if(left==right)
                len++;
            else
                len+=2;
            left--;
            right++;
        }
        left++;
        right--;
        int ansLen = ans.size();
        if(len>ansLen){
            ans = s.substr(left, right-left+1);
        }
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int i = 0; i<n; i++){
            updateAns(i,i,n,ans,s);
            updateAns(i,i+1,n,ans,s);
        }
        return ans;
    }
};