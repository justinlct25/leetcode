
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
        ListNode* rest = reverseList(head->next);
        head->next->next = head; // make head to the last node in reversed
        head->next = NULL; // make next NULL since head is the new last
        return rest;
    }
};