#include<bits/stdc++.h>
using namespace std;

// LeetCode - 1302

struct TreeNode { // This generated by me to remove error in code
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            for(int i = 0; i<size; i++){
                auto temp = q.front();
                sum+=temp->val;
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            ans = sum;
        }
        return ans;
    }
};