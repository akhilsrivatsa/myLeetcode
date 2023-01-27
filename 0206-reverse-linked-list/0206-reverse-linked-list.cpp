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
    void reverse(ListNode *head, ListNode* &temp){
        
        if(head){
            reverse(head->next, temp);
            temp -> next = head;
            temp = temp -> next;
           
            
            
        }
    }
    ListNode* reverseList(ListNode* head) {
        
        ListNode *temp = new ListNode(0);
       
        ListNode* ans = temp;
        reverse(head, temp);
        temp->next = NULL;
        return ans -> next;
        
    }
};