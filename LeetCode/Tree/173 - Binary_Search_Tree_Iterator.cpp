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
class BSTIterator {
public:
    queue<TreeNode*> iterList;
    
    BSTIterator(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur != nullptr || !s.empty()){
            while(cur != nullptr){
                s.push(cur);
                cur = cur->left;//go to left
            }
            cur = s.top();//leftmost
            s.pop();
            iterList.push(cur);
            cur = cur->right;
        }
        
    }
    
    int next() {
        TreeNode* cur = iterList.front();
        iterList.pop();
        return cur->val;        
    }
    
    bool hasNext() {
        return !iterList.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
