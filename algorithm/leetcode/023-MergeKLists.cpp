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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        ListNode *p = lists[0];
        for (int i = 1; i < lists.size(); ++i) {
            p = mergeTwoLists(p, lists[i]);
        }
        return p;
    }
    
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode *p = &dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 != nullptr ? l1 : l2;
        return dummy.next;
    }
};
