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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* fHead = new ListNode();
        ListNode* sHead = new ListNode();
        ListNode* ffHead = fHead; 
        ListNode* ssHead = sHead;
        
        while(head){
            
            if(head-> val < x){
                
                ffHead -> next = head;
                ffHead = ffHead->next;
             }else{
                
                ssHead -> next = head;
                ssHead = ssHead -> next;
                
            }
            head = head -> next;
        }
       
        
        ffHead -> next = sHead->next;
        ssHead->next = NULL;
        return fHead -> next;
        
    }
};