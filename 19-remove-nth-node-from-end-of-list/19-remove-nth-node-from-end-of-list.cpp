/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<bits/stdc++.h>
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         ListNode* dummy = new ListNode();
        dummy->next = head;
        
        //declare pointers
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // traverse through LL n-times
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        // move both pointer until a condition is met
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        // delete nth node
        slow->next = slow->next->next;
        
        return dummy->next;
    }
};