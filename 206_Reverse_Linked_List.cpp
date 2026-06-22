/*
LeetCode 206 - Reverse Linked List

Given the head of a singly linked list, reverse the list and return
the new head of the reversed list.

Approach:
1. Use three pointers:
   - prev: points to the previous node.
   - curr: points to the current node.
   - nextNode: temporarily stores the next node.
2. Traverse the linked list one node at a time.
3. Reverse the direction of the current node's next pointer.
4. Move all pointers one step forward.
5. When traversal is complete, prev will point to the new head
   of the reversed list.

Example:

Original:
1 -> 2 -> 3 -> 4 -> 5 -> NULL

Iteration 1:
NULL <- 1    2 -> 3 -> 4 -> 5

Iteration 2:
NULL <- 1 <- 2    3 -> 4 -> 5

Iteration 3:
NULL <- 1 <- 2 <- 3    4 -> 5

Iteration 4:
NULL <- 1 <- 2 <- 3 <- 4    5

Iteration 5:
NULL <- 1 <- 2 <- 3 <- 4 <- 5

Reversed:
5 -> 4 -> 3 -> 2 -> 1 -> NULL

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != nullptr) {
            ListNode* nextNode = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
};