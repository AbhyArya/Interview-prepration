#include<bits/stdc++.h>
using namespace std;

// LeetCode - 50

class Solution {
    double power(double v,int n){
        if(n==0)
            return 1;
        double temp = power(v,n/2);
        if(n&1){
            if(n>0)
                return v * temp * temp;
            return (temp * temp) / v;
        }
        return temp * temp;
    }
public:
    double myPow(double x, int n) {
        return power(x,n);
    }
};