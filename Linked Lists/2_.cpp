//LeetCode
//25. Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)
            return head;
        //stores the length of the list
        int count = 0;
        ListNode* temp = head,*pre,*curr,*dummy;
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        
        
        dummy = new ListNode(0);
        dummy->next = head;
        pre = dummy;
        curr = pre->next;
        //reverse k group
        while(count >= k){
                for(int i = 0;i<k-1;i++){
                    ListNode* temp = pre->next;
                    pre->next = curr->next;
                    curr->next = curr->next->next;
                    pre->next->next = temp;
                }
            //for next k group
            count = count - k;
            pre = curr;
            curr = pre->next;
        }
    return dummy->next;
    }
};