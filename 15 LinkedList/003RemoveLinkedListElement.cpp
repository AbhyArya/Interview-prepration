#include<bits/stdc++.h>
using namespace std;

// LeetCode - 203

struct ListNode{ // This generated by me to remove error in code
    int val;
    ListNode *next;
    ListNode(int data){
        this->val = data;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return NULL;
        ListNode* rem = removeElements(head->next, val);
        if(head->val == val){
            return rem;
        }
        head->next = rem;
        return head;
    }
};