#include<bits/stdc++.h>
using namespace std;

// GFG - Search in Rotated Array 

class Solution{
    public:
    int search(int arr[], int l, int h, int key){
        while(l<=h){
            int mid = (l+h)>>1;
            if(arr[mid] == key)
                return mid;
            if(arr[mid] < arr[l]){
                if(key>arr[mid] && key<=arr[h])
                    l = mid+1;
                else
                    h = mid-1;
            }else{
                if(key>=arr[l] && key<arr[mid])
                    h = mid-1;
                else
                    l = mid+1;
            }
        }
        return -1;
    }
};