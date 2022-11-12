#include<bits/stdc++.h>
using namespace std;

// GFG - Complete Binary Tree

class Solution{
public:    
    bool isCompleteBT(Node* root){
        queue<Node*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            bool left, right;
            left = right = true;
            for(int i = 0; i<size; i++){
                auto temp = q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                else 
                    left = false;
                if(temp->right)
                    q.push(temp->right);
                else 
                    right = false;
                if(left == false && right == true)
                    return false;
                if(right == false && !q.empty() && q.front()->left)
                    return false;
            }
            int should = pow(2,level);
            if(!q.empty() && q.front()->left && should!=size)
                return false;
            level++;
        }
        return true;
    }
};