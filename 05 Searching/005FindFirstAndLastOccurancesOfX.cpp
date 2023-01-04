#include<bits/stdc++.h>
using namespace std;

// GFG - First And Last Occurrences of X

class Solution{
    int binarySearch(int arr[], int n, int x, int which){
        int left = 0;
        int right = n-1;
        int ans = -1;
        while(left<=right){
            int mid = (left+right)>>1;
            if(arr[mid]==x){
                ans = mid;
                if(which){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }else if(arr[mid]>x){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
    vector<int> find(int arr[], int n , int x ){
        vector<int> ans;
        ans.push_back(binarySearch(arr,n,x,0));
        ans.push_back(binarySearch(arr,n,x,1));
        return ans;
    }
};