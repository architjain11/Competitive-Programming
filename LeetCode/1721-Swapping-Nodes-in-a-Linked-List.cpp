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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* s1=head, *current=head, *s2;
        int n=k-1;

        while(n--)
            current=current->next;
        s2=current;

        while(current->next!=NULL) {
            current=current->next;
            s1=s1->next;
        }
        
        swap(s1->val, s2->val);
        return head;
    }
};