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
    ListNode* mergeNodes(ListNode* head) {
        
        int sum = 0;
        ListNode *ans = new ListNode(0);
        ListNode *dummy = ans;

        while(head){

            if(head -> val  == 0){
                
                if(sum > 0){
                    ans -> next = new ListNode(sum);
                    ans = ans -> next;
                }
                sum = 0;
            }
            sum = sum + head -> val;

            head = head -> next; 
        }
        ans->next = NULL;
        return dummy->next;
    }
};