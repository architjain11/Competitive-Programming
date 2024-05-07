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
    public int twice(ListNode head) {
        if(head == null) return 0;
        int doubled = head.val*2+twice(head.next);
        head.val = doubled%10;
        return doubled/10;
    }

    public ListNode doubleIt(ListNode head) {
        int carryover = twice(head);
        if(carryover!=0)
            head = new ListNode(carryover, head);

        return head;
    }
}