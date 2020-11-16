//Leetcode
//83. Remove Duplicates from Sorted List

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* curr;
        while(temp != NULL && temp->next != NULL){
            if(temp->val == temp->next->val){
                curr = temp;
                    while(temp!=NULL && temp->next !=NULL && temp->val == temp->next->val)
                        temp=temp->next;
                curr->next = temp->next;
               temp = temp->next; 
            }
            else{
                temp=temp->next;
            }
        }
    return head;
    }
};


//Another solution
ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while(cur) {
            while(cur->next && cur->val == cur->next->val) {
                cur->next = cur->next->next;
            }
            cur = cur->next;
        }
        return head;
}