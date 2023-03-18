# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def merge(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        curr = dummy

        while (list1 and list2):
            if list1.val < list2.val:
                curr.next = list1
                list1 = list1.next
            else:
                curr.next = list2
                list2 = list2.next
            curr = curr.next
        
        if (list1):
            curr.next = list1
        elif (list2):
            curr.next = list2

        return dummy.next
        

    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        num_lists = len(lists)
        step = 1
        while step < num_lists:
            for i in range(0, num_lists - step, step * 2):
                lists[i] = self.merge(lists[i], lists[i + step])
            step *= 2
        return lists[0] if num_lists > 0 else None
