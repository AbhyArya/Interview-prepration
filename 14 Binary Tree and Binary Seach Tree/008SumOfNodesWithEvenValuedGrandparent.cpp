#include<bits/stdc++.h>
using namespace std;

// LeetCode - 1315

struct TreeNode { // This generated by me to remove error in code
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int order(TreeNode* root, int parent){
        if(!root)
            return 0;
        int ans = 0;
        if((parent&1)==0){
            if(root->left)
                ans+=root->left->val;
            if(root->right)
                ans+=root->right->val;
        }
        ans+=order(root->left, root->val);
        ans+=order(root->right,root->val);
        return ans;
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        ans+=order(root->left, root->val);
        ans+=order(root->right,root->val);
        return ans;
    }
};