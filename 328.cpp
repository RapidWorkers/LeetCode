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
ListNode* oddEvenList(ListNode* head) {
    ListNode* oddHead = nullptr, * evenHead = nullptr;
    ListNode* curOdd = nullptr, * curEven = nullptr;

    ListNode* newHead = nullptr;
    ListNode* cur = head;

    if (head == nullptr) return nullptr;

    if (cur != nullptr) oddHead = cur;//set to current
    if (cur != nullptr) cur = cur->next;//move to next
    if (cur != nullptr) evenHead = cur;//set to current
    if (cur != nullptr) cur = cur->next;//move to next
    if (oddHead != nullptr) { oddHead->next = nullptr; curOdd = oddHead; }//init odd
    if (evenHead != nullptr) { evenHead->next = nullptr; curEven = evenHead; }//init even

    while (cur != nullptr) {
        curOdd->next = cur;//current is next node
        curOdd = curOdd->next;//move to next odd
        cur = cur->next;//move to next current
        curOdd->next = nullptr;
        if (cur != nullptr) {
            curEven->next = cur;//current is next node
            curEven = curEven->next;//move to next even
            cur = cur->next;//move to next
            curEven->next = nullptr;
        }
    }

    newHead = oddHead;
    while (oddHead->next != nullptr) {
        oddHead = oddHead->next;
    }
    oddHead->next = evenHead;

    return newHead;

}
};