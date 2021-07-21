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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* reverse = head;
        ListNode* reversePrev = nullptr;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            reverse->next = reversePrev;//reverse connection
            reversePrev = reverse;
            reverse = slow;
        }

        if (fast) slow = slow->next;//even

        while (reversePrev && slow) {
            if (reversePrev->val != slow->val) return false;
            reversePrev = reversePrev->next;
            slow = slow->next;
        }

        return true;
    }
};