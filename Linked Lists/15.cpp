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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        if(head==NULL)
            return NULL;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
    return slow;
    }
};




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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        int count = 0;
        if(head==NULL)
            return NULL;
        while(head!=NULL)
        {
            if(count & 1)//if count odd then move slow
                slow = slow->next;
            ++count;
            head = head->next;
        }
    return slow;
    }
};