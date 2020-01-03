/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1 = head, *p2 = head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p = &dummy;
        while (n--) {
            p2 = p2->next;
        }
        while (p2 != nullptr) {
            p = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        p->next = p1->next;
        p1->next = nullptr;
        return dummy.next;
    }
};
