// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    int pi = 0;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        pi = postorder.size()-1;
        return buildUtil(inorder, postorder, 0, inorder.size()-1);
    }
    
    TreeNode* buildUtil(vector<int>& inorder, vector<int>& postorder, int low, int high) {
        if (pi < 0 || low > high) return NULL;
        
        int val = postorder[pi--];
        
        int i;
        for(i = low; i <= high; i++)
            if (val == inorder[i])
                break;
        
        TreeNode* temp = new TreeNode(val);
        temp->right = buildUtil(inorder, postorder, i+1, high);
        temp->left = buildUtil(inorder, postorder, low, i-1);
        
        return temp;
    }
};