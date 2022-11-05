#include<bits/stdc++.h>
using namespace std;

// LeetCode - 140

class Solution {
    void wordBreak(int i, string s,string str, unordered_set<string> &st,vector<string> &ans){
        if(i==s.size()){
            str.pop_back();
            ans.push_back(str);
            return;
        }
        for(int j = i; j<s.size(); j++){
            string temp = s.substr(i,j-i+1);
            if(st.find(temp)!=st.end()){
                wordBreak(j+1,s,str+temp+" ",st,ans);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        unordered_set<string> st;
        for(auto word: wordDict)
            st.insert(word);
        wordBreak(0,s,"",st,ans);
        return ans;
    }
};