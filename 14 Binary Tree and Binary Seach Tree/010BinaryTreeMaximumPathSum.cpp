#include<bits/stdc++.h>
using namespace std;

// LeetCode - 124

class Solution{
    int ans = INT_MIN;
    int f(TreeNode* root){
        if(!root)
            return 0;
        auto l = max(f(root->left),0);
        auto r = max(f(root->right),0);
        ans = max(ans, l+r+root->val);
        return max(l+root->val, r+root->val);
    }
public:
    int maxPathSum(TreeNode* root) {
        auto p = f(root);
        return ans;
    }
};