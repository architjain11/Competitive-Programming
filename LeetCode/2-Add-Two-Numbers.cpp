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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *first=NULL, *current;
        int carry=0;
        while(l1 != NULL || l2 != NULL) {
            int a=l1==NULL?0:l1->val;
            int b=l2==NULL?0:l2->val;
            int ans=a+b;
            
            if(first == NULL) {
                first = new ListNode();
                first->val=(ans+carry)%10;
                first->next=NULL;
                current=first;
            }
            else {
                ListNode *new_node = new ListNode();
                new_node->val=(ans+carry)%10;
                new_node->next=NULL;
                current->next=new_node;
                current=new_node;
            }
                        
            if(ans+carry<10)
                carry = 0;
            else
                carry = 1;
            
            l1=l1==NULL?NULL:l1->next;
            l2=l2==NULL?NULL:l2->next;
                
        }
        if(carry==1) {
            ListNode *new_node = new ListNode();
            new_node->val=1;
            new_node->next=NULL;
            current->next=new_node;
        }
        return first;
        
    }
};