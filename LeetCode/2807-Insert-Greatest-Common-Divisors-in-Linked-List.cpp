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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==NULL) return head;
        
        ListNode* first=head, *second;
        while(first->next!=NULL) {
            second=first->next;
            int gcdVal=__gcd(first->val, second->val);
            
            ListNode* newPtr=new ListNode(gcdVal, second);
            first->next=newPtr;
            first=second;          
        }
        return head;
    }
};