//LeetCode
//92. Reverse Linked List II
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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* pre,*curr;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        pre = dummy;
        
        for(int i=0;i<m-1;i++)
            pre = pre->next;
        
        curr = pre->next;
        //now move curr->next to be in front of pre for n-m times
        for(int i=0;i<n-m;i++){
            ListNode* temp = pre->next;
            pre->next = curr->next;
            curr->next = curr->next->next;
            pre->next->next = temp;
        }
    return dummy->next;    
    }
};