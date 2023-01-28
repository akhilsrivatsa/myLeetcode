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
    ListNode* deleteMiddle(ListNode* head) {
        
        ListNode *fast = head, *slow = head;
        ListNode *prev = new ListNode(0);
        prev -> next = slow;

        if(!head || !head -> next){
            return NULL;
        }


        while(fast && fast -> next){
            fast = fast-> next -> next;
            slow = slow -> next;
            prev = prev -> next;
        }
        prev->next = slow -> next;
        return head;
    }
};