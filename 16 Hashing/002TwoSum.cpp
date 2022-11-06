#include<bits/stdc++.h>
using namespace std;

// LeetCode - 1

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> s;
        int i = 0;
        for(int ele: nums){
            if(s.find(target-ele)!=s.end()){
                return {i,s[target-ele]};
            }
            s[ele] = i;
            i++;
        }
        return {-1,-1};
    }
};