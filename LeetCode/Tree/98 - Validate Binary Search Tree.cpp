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
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        
        //for(auto val : inorder){
        //    cout << val << ' ';
        //}
        //cout << endl;
        
        for(int i = 1; i < inorder.size(); i++){
            //cout << "cmp " << inorder[i - 1] << ' ' << inorder[i] << endl;
            if(inorder[i - 1] >= inorder[i]) return false;
        }
        return true;
    }
    
    void inorderTraversal(TreeNode* curNode, vector<int>& list){
        if(curNode->left) inorderTraversal(curNode->left, list);
        list.push_back(curNode->val);
        if(curNode->right) inorderTraversal(curNode->right, list);
    }
};
