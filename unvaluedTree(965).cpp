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
    void solve(TreeNode* root, unordered_set<int>&st){
        if(root==nullptr) return;
        st.insert(root->val);
        solve(root->left, st);
        solve(root->right, st);
    }
    bool isUnivalTree(TreeNode* root) {
        unordered_set<int>st;
        solve(root, st);
        if(st.size() > 1) return false;
        else return true;
    }
};