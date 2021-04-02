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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int result = 0;
        vector<ListNode*> resultSet;
        
        ListNode* newL1 = l1, *newL2 = l2;
        
        while(newL1 != nullptr && newL2 != nullptr){
            result = newL1->val + newL2->val + carry;
            resultSet.push_back(new ListNode(result % 10));
            carry = result / 10;
            newL1 = newL1->next;
            newL2 = newL2->next;
        }
        
        while(newL1 != nullptr && carry){//process any left l2
            result = newL1->val + carry;
            resultSet.push_back(new ListNode(result % 10));
            carry = result / 10;
            newL1 = newL1->next;
        }
        
        while(newL1 != nullptr){//process any left l2
            result = newL1->val;
            resultSet.push_back(new ListNode(result % 10));
            newL1 = newL1->next;
        }
        
        while(newL2 != nullptr && carry){//process any left l2
            result = newL2->val + carry;
            resultSet.push_back(new ListNode(result % 10));
            carry = result / 10;
            newL2 = newL2->next;
        }
        
        while(newL2 != nullptr){//process any left l2
            result = newL2->val;
            resultSet.push_back(new ListNode(result % 10));
            newL2 = newL2->next;
        }
        
        if(carry)//process carry
            resultSet.push_back(new ListNode(1));
        
        for(int i = 0; i < resultSet.size() - 1; i++){
            resultSet[i]->next = resultSet[i+1];
        }
        
        return resultSet[0];
    }
};