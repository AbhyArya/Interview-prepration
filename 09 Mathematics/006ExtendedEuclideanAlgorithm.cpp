#include<bits/stdc++.h>
using namespace std;

// GFG - Extended Euclidean Algorithm

// ax+by = gcd(a,b)
// gcd(a,b) = gcd(b,a%b)
// gcd(b,a%b) = bx1+(a%b)y1
// ax+by = bx1+(a%b)y1
// ax+by = bx1+(a-(a/b)*b)y1
// ax+by = bx1+ay1-((a/b)*b)y1
// ax+by = bx1-((a/b)*b)y1+ay1
// ax+by = b(x1-(a/b)*y1)+ay1


// x = y1
// y = x1 - (a/b)*y1

// base case if(b==0) gcd = a
//           ax+by = a
//           ax+0  == a
//           hence x = 1 and y = 0

class Solution{
    pair<int,pair<int,int>> euclidean(int a, int b){
        if(b==0){
            return {a,{1,0}};
        }
        auto prevAns = euclidean(b, a%b);
        int gcd = prevAns.first;
        int x1 = prevAns.second.second;
        int y1 = prevAns.second.first-(a/b)*prevAns.second.second;
        return {gcd, {x1, y1}};
    }
public:
    vector<int> gcd(int a, int b){
        int x = 0, y = 0;
        auto ans = euclidean(a, b);
        return {ans.first, ans.second.first, ans.second.second};
    }
};
