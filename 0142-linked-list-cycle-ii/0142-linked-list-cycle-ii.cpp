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
        
       ListNode* curr = head;
       ListNode* slow = head;
       ListNode* fast = head;
        bool found = false;
        
        while(fast && fast->next){
            
            slow = slow -> next;
            fast = fast->next->next;
            
            if(slow == fast){
                found = true;
                break;
            }
        }
        
        if(!found){
            return NULL;
        }
        
        while(curr != slow){
            curr = curr -> next;
            slow = slow -> next;
        }
        return curr;
        
    }
};