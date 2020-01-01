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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode *result = &dummy;
        int carry = 0;
        for ( ;l1 != nullptr || l2 != nullptr; result = result->next) {
            int d1 = (l1 == nullptr ? 0 : l1->val);
            int d2 = (l2 == nullptr ? 0 : l2->val);
            //注意是逆着加，% 为结果，/ 为进位。比如 8 + 7， value = 5, carry = 1
            int value = (d1 + d2 + carry) % 10;
            carry = (d1 + d2 + carry) / 10;
            result->next = new ListNode(value);
            l1 = (l1 == nullptr ? nullptr : l1->next);
            l2 = (l2 == nullptr ? nullptr : l2->next);
        }
        if (carry > 0) {
            result->next = new ListNode(carry);
        }
        return dummy.next;
    }
};
