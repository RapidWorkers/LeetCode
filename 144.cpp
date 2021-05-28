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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        
        if(root == nullptr) return result;
        
        TreeNode* cur;
        stack<TreeNode*> nS;
        nS.push(root);
        
        while(!nS.empty()){
            cur = nS.top();
            nS.pop();
            result.push_back(cur->val);
            
            if(cur->right) nS.push(cur->right);
            if(cur->left) nS.push(cur->left);
        }
        
        return result;
    }
};
