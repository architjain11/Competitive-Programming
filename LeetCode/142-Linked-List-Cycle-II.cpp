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
        unordered_set<ListNode*> vals;
        while(head!=NULL) {
            if(vals.find(head)==vals.end()) {
                vals.insert(head);
                head=head->next;
            }
            else return head;
        }
        return NULL;
    }
};