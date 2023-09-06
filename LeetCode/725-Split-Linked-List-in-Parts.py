# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        length, curr=0, head
        while curr:
            curr=curr.next
            length+=1

        baseLength, rem=length//k, length%k
        curr, ans=head, []

        for i in range(k):
            ans.append(curr)
            for j in range(baseLength-1+(1 if rem else 0)):
                if not curr: break
                curr=curr.next
            
            rem-=(1 if rem else 0)
            if curr: curr.next, curr=None, curr.next

        return ans