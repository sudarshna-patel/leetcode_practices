// https://leetcode.com/problems/same-tree/

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
// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if ( p == NULL && q == NULL) return true;
//         else if (p == NULL || q == NULL) return false;
        
//         return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//     }
// };

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x, TreeNode* l=NULL, TreeNode* r=NULL) : val(x), left(l), right(r) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if ( p == NULL && q == NULL) return true;
    else if (p == NULL || q == NULL) return false;
    
    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    // TreeNode* root1 = new TreeNode(1);
    // root1->left = new TreeNode(2);

    // TreeNode* root2 = new TreeNode(1);
    // root2->right = new TreeNode(2);

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);


    cout << "Trees are: " << isSameTree(root1, root2);
    return 0;
}