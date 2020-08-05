// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildUtil(preorder, inorder, 0, inorder.size()-1);
    }
    
    TreeNode* buildUtil(vector<int>& preorder, vector<int>& inorder, int low, int high) {
        if (pi >= preorder.size() || low > high) return NULL;
        
        int val = preorder[pi++];
        
        int i;
        for(i = low; i <= high; i++)
            if (val == inorder[i])
                break;
        
        TreeNode* temp = new TreeNode(val);
        temp->left = buildUtil(preorder, inorder, low, i-1);
        temp->right = buildUtil(preorder, inorder, i+1, high);
        
        return temp;
    }
};