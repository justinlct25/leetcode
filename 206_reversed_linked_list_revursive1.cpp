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
    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL; // list not exist
        if (!head->next) return head; // list with one node
        ListNode* rest = reverseList(head->next); // go to find the new first node head
        head->next->next = head; // assign next node's pointer point to original head
        head->next = NULL; // swap the direction of pointing / head will be the new last node
        return rest;
    }
};