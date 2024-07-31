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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        ListNode* current = head;
        int length = 1;
        while (current->next) {
            current = current->next;
            length++;
        }

        current->next = head;
        k = k % length;
        int stepsToNewTail = length - k;
        current = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            current = current->next;
        }

        ListNode* newHead = current->next;
        current->next = NULL;

        return newHead;
    }
};