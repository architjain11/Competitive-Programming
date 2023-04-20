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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* prev=head, *curr=head->next;
        while(curr!=NULL) {
            if(curr->val == prev->val) {
                curr=curr->next;
                prev->next=curr;
            }
            else {
                curr=curr->next;
                prev=prev->next;
            }
        }
        return head;
    }
};