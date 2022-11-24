/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        
        if(head == null || head.next == null || head.next.next == null){
            return head;
        }
        
        ListNode odd = head;
        ListNode even = head.next;
        
        ListNode evenHead = even;
        ListNode oddHead  = odd;
        
      
        while(even!=null){
            
            odd.next = even.next;
            
            if(odd.next != null) even.next = odd.next.next;
            
            
            if(odd.next != null)odd = odd.next;
            even = even.next;
        }
        
        
       odd.next = evenHead;
        return oddHead;
        
    }
}