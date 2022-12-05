#include<bits/stdc++.h>
using namespace std;

// GFG - Kadane's Algorithms
// LeetCode - 53
class Solution{
    public:
    long long maxSubarraySum(int arr[], int n){
        long long ans = INT_MIN;
        long long sum = 0;
        for(int i = 0; i<n; i++){
            if(sum<0)
                sum = 0;
            sum+=arr[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};