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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return nullptr;
        if(!l2) return l1;
        if(!l1) return l2;
        
        ListNode* ret;
        if(l1->val <= l2->val) //l1 is smaller, let l1 first
        {
            ret = l1;
            l1 = l1->next;
        }
        else//l2 first
        {
            ret = l2;
            l2 = l2->next;
        }
        
        ListNode* cur = ret;
        
        while(l1 && l2)//while both exists
        {
            if(l1->val <= l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
        
        if(!l2) cur->next = l1;//no more l2, l1 is last
        if(!l1) cur->next = l2;//no more l1, l2 is last
        return ret;
        
        
    }
};
