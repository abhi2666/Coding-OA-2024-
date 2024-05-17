/*
Approach - Just traverse the tree and when you reach the leaf node(with no left and right node), just check its value
*/
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==nullptr) return nullptr;
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        // check 
        if(root->left==nullptr && root->right==nullptr && root->val==target) return nullptr;

        return root;
        
    }
};