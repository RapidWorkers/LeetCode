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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        
        if(root->left == nullptr && root->right == nullptr){
            return 1;
        }
        else if(root->left == nullptr){
            return maxDepth(root->right)+1;
        }
        else if(root->right == nullptr){
            return maxDepth(root->left)+1;
        }
        else{
            int left = maxDepth(root->left);
            int right = maxDepth(root->right);
            return (left > right)?left+1:right+1;
        }
    }
};
