#include<bits/stdc++.h>
using namespace std;

// LeetCode - 852

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size()-1;
        while(left<right){
            int mid = (left+right)>>1;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                return mid;
            if(arr[mid]<arr[mid+1]){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return -1;
    }
};