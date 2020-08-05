// https://leetcode.com/problems/merge-two-binary-trees/

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return buildUtil(t1, t2);
    }
    
    TreeNode* buildUtil(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) return NULL;
        else if (t1 == NULL) return t2;
        else if (t2 == NULL) return t1;
        
        TreeNode* temp = new TreeNode;
        temp->val = t1->val + t2->val;
        temp->left = buildUtil(t1->left, t2->left);
        temp->right = buildUtil(t1->right, t2->right);
        return temp;
    }
};