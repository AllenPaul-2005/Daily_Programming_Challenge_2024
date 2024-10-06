#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to check if two trees are mirror images.
bool isMirror(TreeNode *left, TreeNode *right)
{
    if (!left && !right)
        return true; // Both are null
    if (!left || !right)
        return false; // One of them is null

    // Check if current nodes are equal and their subtrees are mirror images
    return (left->val == right->val) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

// Main function to check if the tree is symmetric
bool isSymmetric(TreeNode *root)
{
    if (!root)
        return true; // An empty tree is symmetric
    return isMirror(root->left, root->right);
}

int main()
{
    // Example tree: [1, 2, 2, 3, 4, 4, 3]
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    bool result = isSymmetric(root);

    // Print the result
    cout << (result ? "true" : "false") << endl;

    // Clean up the dynamically allocated nodes
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
