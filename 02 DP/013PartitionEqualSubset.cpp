#include<bits/stdc++.h>
using namespace std;

// LeetCode - 416

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2)
            return false;
        // subset sum
        sum/=2; 
        int n = nums.size();
        vector<int>dp (sum+1);
        dp[0]=1;
        for(int i = 0; i<n;i++){
            for(int j = sum; j>=nums[i]; j--){
                if(dp[j-nums[i]])
                    dp[j]=1;
            }
        }
        return dp[sum];
    }
};