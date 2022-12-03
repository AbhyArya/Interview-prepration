#include<bits/stdc++.h>
using namespace std;

// LeetCode - 121

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mini = 100000;
        for(int v: prices){
            ans = max(ans, v-mini);
            mini = min(mini, v);
        }
        return ans;
    }
};