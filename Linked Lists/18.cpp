class Solution {
public:
    bool isPalindrome(ListNode* head) {
     vector<int> number;
        ListNode* temp = head;
        
        while(temp!=NULL)
        {
            number.push_back(temp->val);
            temp = temp->next;
        }
        int s = 0;
        int e = number.size()-1;
        while(s<e)
        {
            if(number[s] != number[e])
                return false;
            s++;
            e--;
        }
        return true;
    }
};