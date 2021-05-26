/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        
        TreeNode* cur = root;
        stack<TreeNode*> nS;
        while(cur != nullptr || !nS.empty()){
            while(cur != nullptr){//reach leftmost
                nS.push(cur);
                cur = cur->left;
            }
            cur = nS.top();
            nS.pop();
            
            result.push_back(cur->val);
            cur = cur->right;
        }
        
        return result;
    }
};
