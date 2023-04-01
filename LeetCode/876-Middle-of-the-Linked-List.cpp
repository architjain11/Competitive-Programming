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
    ListNode* middleNode(ListNode* head) {
        int flag=1;
        ListNode* middle;
        while(head!=0) {
            if(flag%2==0) middle=middle->next;
            flag++;
            head=head->next;
        }
        return middle;
    }
};