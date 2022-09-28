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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* end=head;
        ListNode* start=new ListNode(-1, head);
        if(end->next==NULL) {
            ListNode* e(0);
            return e;
        }
        while(n--) end=end->next;
        while(end!=NULL) {
            start=start->next;
            end=end->next;
        }
        start->next=start->next->next;
        if(start->val==-1) head=start->next;
        return head;
    }
};