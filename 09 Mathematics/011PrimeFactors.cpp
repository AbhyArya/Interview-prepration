#include<bits/stdc++.h>
using namespace std;

// GFG - Largest Prime Factor

class Solution{
public: 
    long long int largestPrimeFactor(int N){
        if(N==1)
            return 1;
        long long int n = 2;
        while(N>1){
            if(N%n==0)
                N/=n;
            else
                n++;
        }
        return n;
    }
};