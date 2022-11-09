#include<bits/stdc++.h>
using namespace std;

// GFG - Sieve of Eratosthenes

class Solution{
    public:
        vector<int> sieveOfEratosthenes(int N){
            vector<int> prime(N+1,true);
            prime[1]=false;
            prime[0]=false;
            for(int i = 2; i*i<=N; i++){
                if(prime[i]==true){
                    for(int j = i*i; j<=N; j+=i){
                        prime[j] = false;
                    }
                }
            }
            vector<int> ans;
            for(int i = 2; i<=N; i++){
                if(prime[i])
                    ans.push_back(i);
            }
            return ans;
        }
};