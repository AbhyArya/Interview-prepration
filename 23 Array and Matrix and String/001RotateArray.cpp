#include<bits/stdc++.h>
using namespace std;

// GFG - Rotate Array

class Solution{ // Reversal Algorithm
    public:
    void rotateArr(int arr[], int d, int n){
        d%=n;
        reverse(arr,arr+d);
        reverse(arr+d,arr+n);
        reverse(arr,arr+n);
        return;
    }
};


class Solution{ // Junggling Algorithm
    public:
    void rotateArr(int arr[], int d, int n){
        d %= n;
        int x = gcd(n,d);
        for(int i = 0; i<x; i++){
            int temp = arr[i];
            int j = i;
            while(1){
                int d = (j+k)%n;
                if(d==i)
                    break;
                arr[j] = arr[d];
                j = k;
            }
            arr[j] = temp;
        }
    }
};