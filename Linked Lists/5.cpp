//https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/(refer it for other method)
//mathematically proove krna seekho ki jab loop node milta h then head aur loop node are equidistant(circularly) from the firts node in loop
//LeetCode
//142. Linked List Cycle II
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* p1,*p2,*entry;//fast,slow
        p1 = head;
        entry = head;
        p2 = head;
            while(p1 && p2 && p2->next)
            {
                p1 = p1->next;//slow
                p2 = p2->next->next;//fast
                
                    if (p1 == p2) {                      // there is a cycle
                        while(p1 != entry) {               // found the entry location
                            p1  = p1->next;              //p1 and entry will always meet at the startofloop
                            entry = entry->next;
                        }
                    return entry;
                    }
            }
        return NULL;
        
    }
};