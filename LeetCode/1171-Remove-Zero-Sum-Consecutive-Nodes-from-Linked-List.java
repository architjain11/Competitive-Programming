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
    public ListNode removeZeroSumSublists(ListNode head) {
        ListNode first = new ListNode(0, head), curr = first;

        while(curr != null) {
            int prefixsum = 0;
            ListNode nxt = curr.next;

            while(nxt != null) {
                prefixsum += nxt.val;
                if(prefixsum == 0)
                    curr.next = nxt.next;
                nxt = nxt.next;
            }

            curr = curr.next;
        }

        return first.next;
    }
}