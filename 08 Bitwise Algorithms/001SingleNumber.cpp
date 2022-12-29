#include<bits/stdc++.h>
using namespace std;

// LeetCode - 136

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xors = 0;
        for(int arr: nums)
            xors^=arr;
        return xors;
    }
};

